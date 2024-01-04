/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
/*    THE CLIENT PROCESS */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
    int sockfd;
    struct sockaddr_in lb_addr;
    int portlb;
    sscanf(argv[1], "%d", &portlb);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }

    lb_addr.sin_family = AF_INET;
    inet_aton("127.0.0.1", &lb_addr.sin_addr);
    lb_addr.sin_port = htons(portlb);

    if ((connect(sockfd, (struct sockaddr *)&lb_addr, sizeof(lb_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        exit(0);
    }

    char *buf = recvTCP(sockfd);
    printf("%s\n", buf);
    free(buf);
    close(sockfd);
    return 0;
}