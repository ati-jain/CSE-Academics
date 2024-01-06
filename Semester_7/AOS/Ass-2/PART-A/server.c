#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Only 1 argument required (port number)\n");
        exit(EXIT_FAILURE);
    }
    int sockfd, n;
    int _port = atoi(argv[1]);
    struct sockaddr_in servaddr, cliaddr;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Socket Creation Failed\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(_port);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Unable to bind the socket to local address\n");
        exit(EXIT_FAILURE);
    }

    printf("\nServer running on port %d....\n", _port);

    char buf[100];
    socklen_t clilen;

    while (1)
    {
        clilen = sizeof(cliaddr);

        n = recvfrom(sockfd, (char *)buf, 100, 0, (struct sockaddr *)&cliaddr, &clilen);

        int rcvd_no = *(int *)buf;
        printf("Received data: %d\n", rcvd_no);
    }
    close(sockfd);
    return 0;
}