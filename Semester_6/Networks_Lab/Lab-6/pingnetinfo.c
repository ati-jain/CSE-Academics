/*
    Assignment 6
    Atishay Jain - 20CS30008
    Roopak Priydarshi - 20CS30042
    PingNetInfo

    See the headers.txt file for logs of each packet received.
*/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define MAX_BUF_SIZE 2048
#define MSG_SIZE 1024
#define MAX_TRY 3

clock_t start_time, end_time;
uint16_t icmpSeq = 0;
FILE *fptr;

unsigned short in_cksum(unsigned short *ptr, int nbytes);
char *receive_packet(int sockfd, char *finalIP);
void send_packet(int sockfd, char *ip_addr, char *data, int packSize, int ttl);

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Invalid arguments. Usage: sudo %s <host> <n> <T>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));
    icmpSeq = rand() & 0xffff;
    int n = atoi(argv[2]); // n = no. of times a probe will be sent
    int T = atoi(argv[3]); // T = timedifference b/w two probes
    struct hostent *hent = gethostbyname(argv[1]);
    char *hostIP = (char *)malloc(sizeof(char) * INET_ADDRSTRLEN);
    strcpy(hostIP, inet_ntoa(*(struct in_addr *)hent->h_addr_list[0]));

    char *nodeIP = (char *)malloc(sizeof(char) * INET_ADDRSTRLEN);
    char *finalIP = (char *)malloc(sizeof(char) * INET_ADDRSTRLEN);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    fptr = fopen("headers.txt", "w");
    fprintf(fptr, "Logs:\n\n");
    printf("See headers.txt for logs\n");
    if (!fptr)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    char *msg = (char *)malloc(sizeof(char) * MSG_SIZE);
    memset(msg, 0, MSG_SIZE);
    strcpy(msg, "Hello!");
    double prevLat = 0;
    int tryCount;

    for (int i = 1; i < 255; i++)
    {
        printf("  %d", i);
        fflush(stdout);
        send_packet(sockfd, hostIP, NULL, 0, i);
        tryCount = -1;
        while (!receive_packet(sockfd, finalIP) && ++tryCount < MAX_TRY)
        {
            printf("  *");
            fflush(stdout);
        } // will try to receive packet for 3 times
        if (tryCount == MAX_TRY)
        {
            printf("\n");
            fprintf(fptr, "node not responding, skipping to next hop\n\n");
            fflush(fptr);
            if (i == 1)
                prevLat = 0;
            else
                prevLat = prevLat * i / (i - 1); // heuristic for latency (neede to calculate next link latency)
            continue;
        }

        printf("  %s", finalIP);

        for (int j = 0; j < 4; j++)
        {
            sleep(1);
            send_packet(sockfd, hostIP, NULL, 0, i);
            tryCount = -1;
            while (!receive_packet(sockfd, nodeIP) && ++tryCount < MAX_TRY)
            {
                printf("  *");
                fflush(stdout);
            } // will try to receive packet for 3 times
            if (tryCount == MAX_TRY)
                break;
            if (strcmp(nodeIP, finalIP) != 0) // repeat if the IP comes out to be different
            {
                send_packet(sockfd, hostIP, NULL, 0, i);
                // printf("Packet Sent!\n");
                tryCount = -1;
                while (!receive_packet(sockfd, finalIP) && ++tryCount < MAX_TRY)
                {
                    printf("  *");
                    fflush(stdout);
                } // will try to receive packet for 3 times
                if (tryCount == MAX_TRY)
                    break;
                j = -1;
            }
        }
        if (tryCount == MAX_TRY)
        {
            printf("\n");
            fprintf(fptr, "node not responding, skipping to next hop\n\n");
            fflush(fptr);
            if (i == 1)
                prevLat = 0;
            else
                prevLat = prevLat * i / (i - 1); // heuristic for latency (neede to calculate next link latency)
            continue;
        }

        // sending n empty packets i.e msg = NULL
        double avgLat = 0, lat;
        double band;
        for (int j = 0; j < n; j++)
        {
            send_packet(sockfd, hostIP, NULL, 0, i);
            tryCount = -1;
            while (!receive_packet(sockfd, finalIP) && ++tryCount < MAX_TRY)
            {
                printf("  *");
                fflush(stdout);
            } // will try to receive packet for MAX_TRY no of tries
            if (tryCount == MAX_TRY)
            {
                printf("\n");
                fprintf(fptr, "node not responding, skipping to next hop\n\n");
                fflush(fptr);
                break;
            } // if node not responding, then skip to next hop

            // calculating latency (RTT for empty packet)
            lat = ((end_time - start_time) / (double)CLOCKS_PER_SEC) * 1000;
            avgLat += lat;
            // sending packets with data
            send_packet(sockfd, hostIP, msg, MSG_SIZE, i);
            tryCount = -1;
            while (!receive_packet(sockfd, finalIP) && ++tryCount < MAX_TRY)
            {
                printf("  *");
                fflush(stdout);
            } // will try to receive packet for 3 times
            if (tryCount == MAX_TRY)
            {
                printf("\n");
                fprintf(fptr, "node not responding, skipping to next hop\n\n");
                fflush(fptr);
                break;
            } // if node not responding, then skip to next hop

            // calculating second latency (RTT for packet with data)
            band = ((end_time - start_time) / (double)CLOCKS_PER_SEC) * 1000;
            band -= lat;   // subtracting the latency to find extra time taken for payload
            if (band == 0) // if RTT is 0, then set it to 0.0001 (to avoid division by 0)
                band = 0.0001;
            band = MSG_SIZE * 1000 / band / 1024 / 1024; // converting to MBps (Mega bytes per second)

            lat -= prevLat; // subtracting the latency till previous node to find link latency
            printf("\t%.4lfms\t%.4lfMBps\t", lat, band);
            sleep(T); // sleep for T seconds
        }
        printf("\n");
        if (tryCount == MAX_TRY)
        { // heuristic for latency (neede to calculate next link latency)
            if (i == 1)
                prevLat = 0;
            else
                prevLat = prevLat * i / (i - 1);
            continue;
        }
        avgLat /= n;
        prevLat = avgLat;

        if (strcmp(nodeIP, hostIP) == 0)
        { // if the node is the destination
            fprintf(fptr, "Destination Reached");
            break;
        }
    }
    fclose(fptr);
}

void setICMP(char *buf, char *data, int dataSize, int size)
{ // setting ICMP header
    struct icmphdr *icmp_hdr = (struct icmphdr *)buf;
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = getpid() & 0xFFFF;
    icmp_hdr->un.echo.sequence = icmpSeq;
    icmp_hdr->checksum = 0;
    memcpy(buf + sizeof(struct icmphdr), data, dataSize);

    icmp_hdr->checksum = in_cksum((unsigned short *)icmp_hdr, size); // 20 is ip header size
}

void setIP(struct iphdr *ip_hdr, int packSize, struct sockaddr_in *dest_addr, int ttl)
{ // setting IP header
    ip_hdr->ihl = sizeof(struct iphdr) / 4;
    ip_hdr->version = 4;
    ip_hdr->tos = 0;
    ip_hdr->tot_len = htons(packSize);
    ip_hdr->id = htons(0);
    ip_hdr->frag_off = htons(0);
    ip_hdr->ttl = ttl;
    ip_hdr->protocol = IPPROTO_ICMP;
    ip_hdr->check = 0;
    ip_hdr->saddr = INADDR_ANY;
    ip_hdr->daddr = dest_addr->sin_addr.s_addr;

    ip_hdr->check = in_cksum((unsigned short *)ip_hdr, 4 * ip_hdr->ihl);
}

void send_packet(int sockfd, char *ip_addr, char *data, int size, int ttl)
{ // sending packet to ip_addr with data of size = size, with ttl = ttl
    // setting destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    inet_aton(ip_addr, &dest_addr.sin_addr);

    // setting packet
    int packSize = sizeof(struct iphdr) + sizeof(struct icmphdr) + size;

    char packet[packSize];
    struct iphdr *ip_hdr = (struct iphdr *)packet;
    setIP(ip_hdr, packSize, &dest_addr, ttl);

    setICMP(packet + 4 * ip_hdr->ihl, data, size, packSize - 4 * ip_hdr->ihl);

    if (sendto(sockfd, packet, packSize, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
    {   // sending packet
        perror("sendto error");
        return;
    }

    // record start time
    start_time = clock();
    return;
}

char *receive_packet(int sockfd, char *finalIP)
{ // receiving packet and returning the ip address of the node from which it was received
    // setting timeout
    char buf[MAX_BUF_SIZE];
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);

    struct timeval time;
    time.tv_sec = 3;
    time.tv_usec = 0;

    // setting timeout
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&time, sizeof(time));

    // receiving packet
    int bytes = recvfrom(sockfd, buf, MAX_BUF_SIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
    if (bytes < 0)
    {
        return NULL;
    }

    // record end time
    end_time = clock();

    // print all ip header fields
    struct iphdr *ip_hdr = (struct iphdr *)buf;

    // print all icmp header fields
    struct icmphdr *icmp_hdr = (struct icmphdr *)(buf + (ip_hdr->ihl * 4));
    // print all icmp header fields
    fprintf(fptr, "Packet recieved from %s\n", inet_ntoa((struct in_addr){ip_hdr->saddr}));
    fprintf(fptr, "ICMP Header Recieved with fields:\n");
    fprintf(fptr, "  icmp_hdr->type: %d\n", icmp_hdr->type);
    fprintf(fptr, "  icmp_hdr->code: %d\n", icmp_hdr->code);
    fprintf(fptr, "  icmp_hdr->checksum: %d\n", icmp_hdr->checksum);
    fprintf(fptr, "  icmp_hdr->un.echo.id: %d\n", icmp_hdr->un.echo.id);
    fprintf(fptr, "  icmp_hdr->un.echo.sequence: %d\n", icmp_hdr->un.echo.sequence);
    fprintf(fptr, "\n\n");

    if (icmp_hdr->type != ICMP_TIME_EXCEEDED && icmp_hdr->un.echo.sequence != icmpSeq)
    { // if packet is not a time exceeded packet or not the packet we sent
        fprintf(fptr, "Packet discarded!\n");
        char *data = buf + (ip_hdr->ihl * 4) + sizeof(struct icmphdr);
        fprintf(fptr, "  Data: %s\n", data);
        // print all ip header fields
        fprintf(fptr, "IP Header Recieved with fields:\n");
        fprintf(fptr, "  ip_hdr->ihl: %d\n", ip_hdr->ihl);
        fprintf(fptr, "  ip_hdr->version: %d\n", ip_hdr->version);
        fprintf(fptr, "  ip_hdr->tos: %d\n", ip_hdr->tos);
        fprintf(fptr, "  ip_hdr->tot_len: %d\n", ip_hdr->tot_len);
        fprintf(fptr, "  ip_hdr->id: %d\n", ip_hdr->id);
        fprintf(fptr, "  ip_hdr->frag_off: %d\n", ip_hdr->frag_off);
        fprintf(fptr, "  ip_hdr->ttl: %d\n", ip_hdr->ttl);
        fprintf(fptr, "  ip_hdr->protocol: %d\n", ip_hdr->protocol);
        fprintf(fptr, "  ip_hdr->check: %d\n", ip_hdr->check);
        fprintf(fptr, "  ip_hdr->saddr: %d\n", ip_hdr->saddr);
        fprintf(fptr, "  ip_hdr->daddr: %d\n", ip_hdr->daddr);
        fprintf(fptr, "IP next protocol:\n");
        if (ip_hdr->protocol == IPPROTO_TCP)
        {
            // Extract TCP header
            struct tcphdr *tcp_header = (struct tcphdr *)(buf + 4 * ip_hdr->ihl);
            // Print TCP header
            printf("TCP Header:\n");
            printf("  Source Port: %u\n", ntohs(tcp_header->source));
            printf("  Destination Port: %u\n", ntohs(tcp_header->dest));
            printf("  Sequence Number: %u\n", ntohl(tcp_header->seq));
            printf("  Acknowledgement Number: %u\n", ntohl(tcp_header->ack_seq));
            printf("  Header Length: %u bytes\n", tcp_header->doff * 4);
            printf("  Flags: 0x%02x\n", tcp_header->th_flags);
            printf("  Window Size: %u\n", ntohs(tcp_header->window));
            printf("  Checksum: 0x%04x\n", ntohs(tcp_header->check));
            printf("  Urgent Pointer: %u\n", ntohs(tcp_header->urg_ptr));
        }
        else if (ip_hdr->protocol == IPPROTO_UDP)
        {
            // Extract UDP header
            struct udphdr *udp_header = (struct udphdr *)(buf + 4 * ip_hdr->ihl);
            // Print UDP header
            printf("UDP Header:\n");
            printf("  Source Port: %u\n", ntohs(udp_header->source));
            printf("  Destination Port: %u\n", ntohs(udp_header->dest));
            printf("  Length: %u bytes\n", ntohs(udp_header->len));
            printf("  Checksum: 0x%04x\n", ntohs(udp_header->check));
        }
        else
        {   // Print other protocols
            printf("Unknown Protocol\n");
        }

        fprintf(fptr, "\n\n");
        fflush(fptr);
        return NULL;
    }
    // copy ip address to finalIP
    strcpy(finalIP, inet_ntoa(src_addr.sin_addr));
    icmpSeq++;
    return finalIP;
}

// function to calculate checksum
uint16_t in_cksum(uint16_t *addr, int len)
{ // addr is the pointer to the start of the data, len is the length of the data
    int nleft = len;
    uint32_t sum = 0;
    uint16_t *w = addr;
    uint16_t answer = 0;

    // sum up 2-byte values until none or only one byte left
    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }

    // add left-over byte, if any
    if (nleft == 1)
    {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    // fold 32-bit sum into 16 bits
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    // take the one's complement of sum
    answer = ~sum;
    return answer;
}