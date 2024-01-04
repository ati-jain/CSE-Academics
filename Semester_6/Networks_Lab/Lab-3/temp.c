/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
/* THE SERVER PROCESS */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFSIZE 50

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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid command line arguments!\n");
        exit(0);
    }
    int sockfd, newsockfd; /* Socket descriptors */
    int clilen;
    struct sockaddr_in cli_addr, serv_addr;
    int port;
    sscanf(argv[1], "%d", &port);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Cannot create socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* With the information provided in serv_addr, we associate the server
       with its port using the bind() system call.
    */
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Unable to bind local address\n");
        exit(0);
    }

    listen(sockfd, 5); /* This specifies that up to 5 concurrent client
                  requests will be queued up while the system is
                  executing the "accept" system call below.
               */

    printf("server running...\n");
    srand(time(0));

    while (1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr,
                           &clilen);

        if (newsockfd < 0)
        {
            perror("Accept error\n");
            exit(0);
        }

        char *buf = recvTCP(newsockfd);
        // char buf[100];
        // recv(newsockfd, buf, 100, 0);

        if (strcmp(buf, "Send Time") == 0)
        {
            time_t t;
            time(&t);
            strcpy(buf, ctime(&t));
            send(newsockfd, buf, strlen(buf) + 1, 0);
            printf("Time sent: %s", buf);
        }

        else if (strcmp(buf, "Send Load") == 0)
        {
            sprintf(buf, "%d", (rand() % 100) + 1);
            send(newsockfd, buf, strlen(buf) + 1, 0);
            printf("Load sent: %s\n", buf);
        }

        else
            printf("Invalid request\n");
        free(buf);
        close(newsockfd);
    }
    return 0;
}