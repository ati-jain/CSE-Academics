/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
// A Simple UDP Server that sends a dat and time
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8181);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server Running....\n");

    int n, len;
    char buffer[MAXLINE];

    len = sizeof(cliaddr);
    while (1)
    {
        n = recvfrom(sockfd, (void *)buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';
        time_t t;
        time(&t);
        strcpy(buffer, ctime(&t));
        // sleep(10);
        sendto(sockfd, (const char *)buffer, strlen(buffer), 0, (const struct sockaddr *)&cliaddr, len);
    }
    close(sockfd);
    return 0;
}