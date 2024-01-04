#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 1
#define MAX_RETRIES 3

struct icmp_packet
{
    struct icmphdr icmp_hdr;
    char data[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short calculate_checksum(unsigned short *addr, int len)
{
    unsigned int sum = 0;
    unsigned short answer = 0;
    unsigned short *w = addr;
    int nleft = len;

    while (nleft > 1)
    {
        sum += *w++;
        nleft -= 2;
    }
    if (nleft == 1)
    {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

int send_ping(int sockfd, struct sockaddr_in *addr, int seq)
{
    struct icmp_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.icmp_hdr.type = ICMP_ECHO;
    packet.icmp_hdr.code = 0;
    packet.icmp_hdr.un.echo.id = htons(getpid());
    packet.icmp_hdr.un.echo.sequence = htons(seq);
    gettimeofday((struct timeval *)&packet.data, NULL);
    packet.icmp_hdr.checksum = calculate_checksum((unsigned short *)&packet, sizeof(packet));
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) == -1)
    {
        perror("sendto");
        return -1;
    }
    return 0;
}

int recv_ping(int sockfd, struct sockaddr_in *addr, int seq, struct timeval *start_time)
{
    struct icmp_packet packet;
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    memset(&packet, 0, sizeof(packet));
    int ret = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&from_addr, &from_len);
    if (ret == -1)
    {
        perror("recvfrom");
        return -1;
    }
    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    if (packet.icmp_hdr.type == ICMP_ECHOREPLY && packet.icmp_hdr.un.echo.id == htons(getpid()) &&
        packet.icmp_hdr.un.echo.sequence == htons(seq))
    {
        double rtt = (end_time.tv_sec - start_time->tv_sec) * 1000.0 +
                     (end_time.tv_usec - start_time->tv_usec) / 1000.0;
        printf("Reply from %s: bytes=%d time=%.2f ms\n",
               inet_ntoa(from_addr.sin_addr), ret, rtt);
        return 0;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (addr.sin_addr.s_addr == INADDR_NONE)
    {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return -1;
    }
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1)
    {
        perror("socket");
        return -1;
    }
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &(int){1}, sizeof(int)) == -1)
    {
        perror("setsockopt");
        return -1;
    }
    int seq = 1;
    int retries = 0;
    while (retries < MAX_RETRIES)
    {
        if (send_ping(sockfd, &addr, seq) == -1)
        {
            return -1;
        }
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);
        struct timeval timeout;
        timeout.tv_sec = MAX_WAIT_TIME;
        timeout.tv_usec = 0;
        int ret = select(sockfd + 1, &rfds, NULL, NULL, &timeout);
        if (ret == -1)
        {
            perror("select");
            return -1;
        }
        else if (ret == 0)
        {
            printf("Request timed out\n");
            retries++;
            continue;
        }
        else
        {
            if (recv_ping(sockfd, &addr, seq, &start_time) == 0)
            {
                break;
            }
            retries++;
        }
    }
    close(sockfd);
    return 0;
}