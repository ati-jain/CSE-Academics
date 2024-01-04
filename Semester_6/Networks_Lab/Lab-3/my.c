#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFSIZE 50 // max send/ recv size

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

    int port; // check if port value entered by user
    if (argc != 2)
    {
        printf("Invalid command line arguments!\n");
        exit(0);
    }
    srand(time(NULL)); // initialise random number as (unique) seed
    time_t t;          // create time object
    struct tm *tm;

    int sockfd, newsockfd;
    int clilen;
    struct sockaddr_in cli_addr, serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Unable to bind local address\n");
        exit(0);
    }

    printf("erver running ...");

    listen(sockfd, 5);
    char buff[100];
    char *req;

    while (1)
    {

        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if (newsockfd < 0)
        {
            perror("Accept error\n");
            exit(0);
        }

        req = recvTCP(newsockfd);
        // printf("%s %d\n", req, strlen(req));
        if (strcmp(req, "Send Time") == 0)
        {
            t = time(NULL);
            tm = localtime(&t);                     // initialise time object with local-time
            strftime(buff, sizeof(buff), "%c", tm); // convert to string to be sent
            // time sent in readable date-time format, no need to proccess on client side
            send(newsockfd, buff, strlen(buff) + 1, 0);
            printf("Time sent: %s\n", buff);
        }
        else if (strcmp(req, "Send Load") == 0)
        {
            sprintf(buff, "%d", (rand() % 100) + 1); // generate random no (1 t0 100)
            send(newsockfd, buff, strlen(buff) + 1, 0);
            printf("Load sent: %s\n", buff);
        }
        free(req);
        close(newsockfd);
    }
    return 0;
}