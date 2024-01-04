#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "mysocket.h"

int main()
{
    int sockfd, newsockfd; /* Socket descriptors */
    int clilen;
    struct sockaddr_in cli_addr, serv_addr;
    int port = 5000;

    if ((sockfd = my_socket(AF_INET, SOCK_MyTCP, 0)) < 0)
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
    if (my_bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Unable to bind local address\n");
        exit(0);
    }

    my_listen(sockfd, 5); /* This specifies that up to 5 concurrent client
                  requests will be queued up while the system is
                  executing the "accept" system call below.
               */

    printf("server running...\n");

    while (1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = my_accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        // printf("socket created");
        // fflush(stdout);
        // printf("Client Connected!\n");
        // fflush(stdout);
        // if (newsockfd < 0)
        // {
        //     perror("Accept error\n");
        //     exit(0);
        // }

        // char *buf = (char *)calloc(5000, sizeof(char));
        // strcpy(buf, "Message from Server");
        // for (int i = 0; i < 10000; i++)
        // {
        //     sprintf(buf, "hello %d", i);
        //     my_send(newsockfd, buf, strlen(buf) + 1, 0);
        // }
        // memset(buf, 0, 100);
        // printf("Sent!\n");
        // fflush(stdout);
        // int ret = my_recv(newsockfd, buf, 50, 0);
        // printf("%s\n", buf);
        // fflush(stdout);
        // my_recv(newsockfd, buf, 50, 0);
        // printf("%s\n", buf);

        // my_send(newsockfd, "testing", strlen("testing") + 1, 0);
        // for (int i = 0; i < 10000; i++)
        // {
        //     my_recv(sockfd, buf, 5000, 0);
        //     // printf("%d) %s\n", i, buf);
        // }

        // printf("%s\n", buf);

        // free(buf);
        printf("There\n");
        my_close(newsockfd);
    }
    return 0;
}