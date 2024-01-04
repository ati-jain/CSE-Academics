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

int main()
{
    int sockfd, newsockfd;

    struct sockaddr_in serv, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(2000);

    bind(sockfd, (struct sockaddr *)&serv, sizeof(serv));

    listen(sockfd, 5);

    struct pollfd fds[1];
    int rc;
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;

    rc = poll(fds, 1, 10000);

    if (rc == 0)
        close(sockfd);
    else if (fds[0].revents == POLLIN)
    {

        int clilen = sizeof(cli);

        newsockfd = accept(sockfd, (struct sockaddr *)&cli, &clilen);

        if (fork() == 0)
        {
            close(sockfd);
            char buf[10];

            recv(sockfd, buf, 10, 0);

            strcpy(buf, "sending");
            send(sockfd, buf, strlen(buf) + 1, 0);

            close(newsockfd);
            exit(0);
        }
        else
        {
            close(newsockfd);
        }
    }

    close(sockfd);

    return 0;
}