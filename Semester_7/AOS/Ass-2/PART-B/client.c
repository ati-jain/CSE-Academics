#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/poll.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Only 1 argument required (port number)\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    int sockfd;
    int _port = atoi(argv[1]);
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(_port);
    inet_aton("172.18.0.2", &servaddr.sin_addr);
    while (1)
    {
        char buf[20];
        // Generate random sleep time
        int sleep_time = rand() % 25 + 1;
        // Sending once to establish connection
        sendto(sockfd, (const char *)&sleep_time, sizeof(int), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        printf("Sleep time sent: %d seconds\n", sleep_time);
        sleep(1);
    }
    close(sockfd);
    return 0;
}