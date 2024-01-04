/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
/* THE LOAD BALANCER PROCESS */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFSIZE 50

/* THE SERVER PROCESS */

char *recvTCP(int sockfd)
{
    char *buf = (char *)calloc(1, sizeof(char));
    char tmpbuff[BUFFSIZE + 1];
    int t = 0, n = 0;
    do
    {
        t = recv(sockfd, tmpbuff, BUFFSIZE, 0);
        tmpbuff[t] = '\0';
        buf = (char *)realloc(buf, n + t + 1);
        strcat(buf, tmpbuff);
        n += t;
    } while (t > 0 && tmpbuff[t - 1] != '\0');
    return buf;
}

void askLoad(struct sockaddr_in *server, int *load)
{
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }

    if ((connect(sockfd, (struct sockaddr *)server, sizeof(*server))) < 0)
    {
        perror("Unable to 0 connect to server\n");
        exit(0);
    }

    send(sockfd, "Send Load", strlen("Send Load") + 1, 0);

    char *buf = recvTCP(sockfd);
    sscanf(buf, "%d", load); /* getting load from server-1 */
    free(buf);

    char buffer[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(*server).sin_addr, buffer, sizeof(buffer));
    printf("Load received from %s:%d %d\n", buffer, ntohs(server->sin_port), *load);
    close(sockfd);
    return;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Invalid command line arguments!\n");
        exit(0);
    }
    int sockfd, sockfd2, newsockfd; /* Socket descriptors */
    int clilen;
    struct sockaddr_in cli_addr, lb_addr, serv_addr1, serv_addr2;
    int portlb, ports1, ports2;

    sscanf(argv[1], "%d", &portlb);
    sscanf(argv[2], "%d", &ports1);
    sscanf(argv[3], "%d", &ports2);

    int loads[2];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Cannot create socket\n");
        exit(0);
    }

    /*load balancer socket */
    lb_addr.sin_family = AF_INET;
    lb_addr.sin_addr.s_addr = INADDR_ANY;
    lb_addr.sin_port = htons(portlb);

    if (bind(sockfd, (struct sockaddr *)&lb_addr, sizeof(lb_addr)) < 0)
    {
        printf("Unable to bind local address\n");
        exit(0);
    }

    /* server-1 socket */
    serv_addr1.sin_family = AF_INET;
    inet_aton("127.0.0.1", &serv_addr1.sin_addr);
    serv_addr1.sin_port = htons(ports1);

    /* server-2 socket */
    serv_addr2.sin_family = AF_INET;
    inet_aton("127.0.0.1", &serv_addr2.sin_addr);
    serv_addr2.sin_port = htons(ports2);

    listen(sockfd, 5);

    struct pollfd fds[1];
    int nfds = 1, rc;
    int timeout = 5000, elapsed = 0; // 5 second load refresh

    memset(fds, 0, sizeof(fds));
    fds[0].fd = sockfd;
    fds[0].events = POLLIN; // Set up the listening socket

    time_t start_t, end_t;
    askLoad(&serv_addr1, &loads[0]);
    askLoad(&serv_addr2, &loads[1]);
    time(&start_t);
    while (1)
    {
        clilen = sizeof(cli_addr);
        if (timeout <= elapsed)
            rc = 0;
        else
            rc = poll(fds, nfds, timeout - elapsed);

        if (rc < 0) // if the poll call failed
        {
            perror("\tpoll() error\n");
            break;
        }
        else if (rc == 0) // if timeout expired
        {
            askLoad(&serv_addr1, &loads[0]);
            askLoad(&serv_addr2, &loads[1]);
            time(&start_t);
            elapsed = 0;
        }
        else if (fds[0].revents == POLLIN) // if there is client request
        {
            time(&end_t);
            elapsed = difftime(end_t, start_t) * 1000; // calculating the time elapsed
            newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
            if (newsockfd < 0)
            {
                printf("Accept error\n");
                exit(0);
            }

            if (fork() == 0)
            {
                close(sockfd);
                if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                {
                    perror("Unable to create socket\n");
                    exit(0);
                }

                if (loads[0] < loads[1])
                {
                    if ((connect(sockfd2, (struct sockaddr *)&serv_addr1, sizeof(serv_addr1))) < 0)
                    {
                        perror("Unable to 0 connect to server\n");
                        exit(0);
                    }
                    char buffer[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &serv_addr1.sin_addr, buffer, sizeof(buffer));
                    printf("Sending client request to %s:%d\n", buffer, ntohs(serv_addr1.sin_port));
                }
                else
                {
                    if ((connect(sockfd2, (struct sockaddr *)&serv_addr2, sizeof(serv_addr2))) < 0)
                    {
                        perror("Unable to 0 connect to server\n");
                        exit(0);
                    }
                    char buffer[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &serv_addr2.sin_addr, buffer, sizeof(buffer));
                    printf("Sending client request to %s:%d\n", buffer, ntohs(serv_addr2.sin_port));
                }

                send(sockfd2, "Send Time", strlen("Send Time") + 1, 0); // send time request to server
                char *buf = recvTCP(sockfd2);                           // receiving time
                close(sockfd2);                                         // closing the socket
                send(newsockfd, buf, strlen(buf) + 1, 0);               // sending time to client
                free(buf);
                exit(0);
            }
            close(newsockfd);
        }
    }
    return 0;
}
