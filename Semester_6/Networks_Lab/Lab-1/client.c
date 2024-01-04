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
#define BUFFSIZE 9

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;

    int i;
    // char buf[100];

    /* Opening a socket is exactly similar to the server process */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }

    /* Recall that we specified INADDR_ANY when we specified the server
       address in the server. Since the client can run on a different
       machine, we must specify the IP address of the server.

       In this program, we assume that the server is running on the
       same machine as the client. 127.0.0.1 is a special address
       for "localhost" (this machine)

    /* IF YOUR SERVER RUNS ON SOME OTHER MACHINE, YOU MUST CHANGE
           THE IP ADDRESS SPECIFIED BELOW TO THE IP ADDRESS OF THE
           MACHINE WHERE YOU ARE RUNNING THE SERVER.
        */

    serv_addr.sin_family = AF_INET;
    inet_aton("127.0.1.1", &serv_addr.sin_addr);
    serv_addr.sin_port = htons(20001);

    /* With the information specified in serv_addr, the connect()
       system call establishes a connection with the server process.
    */
    if ((connect(sockfd, (struct sockaddr *)&serv_addr,
                 sizeof(serv_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        exit(0);
    }
    printf("Queued Successfully!!!\n\n");
    /* After connection, the client can send or receive messages.
       However, please note that recv() will block when the
       server is not sending and vice versa. Similarly send() will
       block when the server is not receiving and vice versa. For
       non-blocking modes, refer to the online man pages.
    */
    char buf[BUFFSIZE];
    int new, len;
    while (1)
    {
        new = 1;
        printf("Enter Expression : ");
        while (fgets(buf, BUFFSIZE, stdin))
        {
            len = strlen(buf);
            if (new && !strcmp(buf, "-1\n"))
            {
                close(sockfd);
                exit(0);
            }
            if (buf[len - 1] == '\n')
            {
                buf[len - 1] = '\0';
                if (send(sockfd, buf, len, 0) < 0)
                {
                    perror("Send Error!");
                    exit(1);
                }
                break;
            }
            if (send(sockfd, buf, BUFFSIZE - 1, 0) < 0)
            {
                perror("Send Error!");
                exit(1);
            }
            new = 0;
        }

        recv(sockfd, buf, 100, 0);
        printf("Value : %s\n", buf);
    }
    close(sockfd);
    return 0;
}
