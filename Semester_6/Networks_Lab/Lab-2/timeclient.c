/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
// A Simple Client Implementation
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLEN 1024

int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&cliaddr, 0, sizeof(cliaddr));

    // Server information
    servaddr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(8181);

    int n, len;
    char *str = "send time";
    char buf[MAXLEN];
    struct pollfd fds[1];
    int nfds = 1, rc, timeout = 3000;

    memset(fds, 0, sizeof(fds)); // Initialize the pollfd structure
    fds[0].fd = sockfd;
    fds[0].events = POLLIN; // Set up the listening socket

    for (int t = 1; t <= 5; t++)
    {
        // send request to UDP server to get time

        sendto(sockfd, (const char *)str, strlen(str), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        // Call poll() and wait 3 seconds for it to complete
        printf("Try %d: Waiting...", t);
        rc = poll(fds, nfds, timeout);

        if (rc < 0) // if the poll call failed
        {
            perror("\tpoll() error\n");
            break;
        }
        else if (rc == 0) // if timeout expired
        {
            printf("\ttimed out.\n");
        }
        else if (fds[0].revents == POLLIN)
        {
            n = recvfrom(sockfd, (char *)buf, MAXLEN, 0, (struct sockaddr *)&servaddr, &len);
            if (n > 0)
            {
                buf[n] = '\0';
                printf("\tsuccessfull!\nTime: %s\n", buf);
            }
            close(sockfd);
            exit(0);
        }
    }
    printf("No response!\n");
    close(sockfd);
    return 0;
}