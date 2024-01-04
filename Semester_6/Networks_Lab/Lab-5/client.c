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
    inet_aton("127.0.0.1", &serv_addr.sin_addr);
    serv_addr.sin_port = htons(port);
    /* With the information provided in serv_addr, we associate the server
       with its port using the bind() system call.
    */
    if ((my_connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        exit(0);
    }
    // sleep(2);

    /* After connection, the client can send or receive messages.
       However, please note that recv() will block when the
       server is not sending and vice versa. Similarly send() will
       block when the server is not receiving and vice versa. For
       non-blocking modes, refer to the online man pages.
    */
    char buf[5000];
    // for (int i = 0; i < 100; i++)
    //     buf[i] = '\0';
    for (int i = 0; i < 10000; i++)
    {
        my_recv(sockfd, buf, 5000, 0);
        // printf("%d) %s\n", i, buf);
    }

    printf("recieved main: %s\n", buf);

    strcpy(buf, "Message from client");
    int s = my_send(sockfd, buf, strlen(buf) + 1, 0);

    strcpy(buf, "Message from client2");
    my_send(sockfd, buf, strlen(buf) + 1, 0);

    my_recv(sockfd, buf, 100, 0);
    printf("%s\n", buf);

    for (int i = 0; i < 10000; i++)
    {
        sprintf(buf, "hello %d", i);
        my_send(newsockfd, buf, strlen(buf) + 1, 0);
    }
    printf("Main Sent! %d\n", s);
    my_close(sockfd);
    return 0;
}