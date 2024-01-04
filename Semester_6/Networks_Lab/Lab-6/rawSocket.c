#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PACKET_SIZE 64

unsigned short in_cksum(unsigned short *ptr, int nbytes);
void receive_packet(int sockfd);
void send_packet(int sockfd, char *ip_addr, char *data);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket");
        return 1;
    }

    int optval = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(optval)) < 0)
    {
        perror("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    char *ip_addr = argv[1];
    char *msg = "HELLO THERE!";
    while (1)
    {
        send_packet(sockfd, ip_addr, msg);
        printf("Packet Sent!\n");

        receive_packet(sockfd);
    }
}

void setICMP(struct icmp *icmp_hdr, char *data, int size)
{
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;
    memcpy(icmp_hdr->icmp_data, data, strlen(data) + 1);

    icmp_hdr->icmp_cksum = in_cksum((unsigned short *)icmp_hdr, size); // 20 is ip header size
}

void setIP(struct iphdr *ip_hdr, char *ip_addr)
{
    ip_hdr->ihl = 5;
    ip_hdr->version = 4;
    ip_hdr->tos = 0;
    ip_hdr->tot_len = htons(PACKET_SIZE);
    ip_hdr->id = htons(0);
    ip_hdr->frag_off = htons(0);
    ip_hdr->ttl = 255;
    ip_hdr->protocol = IPPROTO_ICMP;
    ip_hdr->check = 0;
    ip_hdr->saddr = INADDR_ANY;
    ip_hdr->daddr = inet_addr(ip_addr);

    ip_hdr->check = in_cksum((unsigned short *)ip_hdr, 4 * ip_hdr->ihl);
}

void send_packet(int sockfd, char *ip_addr, char *data)
{
    struct hostent *he = gethostbyname(ip_addr);
    if (he == NULL)
    {
        perror("gethostbyname");
        return;
    }

    // print host ip
    printf("Sending to IP: %s\n", inet_ntoa(*(struct in_addr *)he->h_addr_list[0]));

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);
    inet_aton(inet_ntoa(*(struct in_addr *)he->h_addr_list[0]), &dest_addr.sin_addr);

    char packet[PACKET_SIZE];
    struct iphdr *ip_hdr = (struct iphdr *)packet;
    setIP(ip_hdr, inet_ntoa(*((struct in_addr *)he->h_addr)));

    struct icmp *icmp_hdr = (struct icmp *)(packet + 4 * ip_hdr->ihl);
    setICMP(icmp_hdr, data, PACKET_SIZE - 4 * ip_hdr->ihl);

    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
    {
        perror("sendto");
        return;
    }
}

void receive_packet(int sockfd)
{
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        perror("setsockopt");
        return;
    }
    char buf[PACKET_SIZE];
    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);

    int bytes = recvfrom(sockfd, buf, PACKET_SIZE, 0, (struct sockaddr *)&src_addr, &src_addr_len);
    if (bytes < 0)
    {
        perror("recvfrom error");
        return;
    }
    printf("\nReceived %d bytes from %s\n", bytes, inet_ntoa(src_addr.sin_addr));

    struct iphdr *ip_hdr = (struct iphdr *)buf;
    struct icmp *icmp_hdr = (struct icmp *)(buf + (ip_hdr->ihl * 4));

    char *data = icmp_hdr->icmp_data;
    printf("Received Message: %s\n", data);
}

unsigned short in_cksum(unsigned short *ptr, int nbytes)
{
    unsigned long sum;
    unsigned short oddbyte;
    unsigned short answer;

    sum = 0;
    while (nbytes > 1)
    {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1)
    {
        oddbyte = 0;
        *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = (unsigned short)~sum;

    return answer;
}