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

int main()
{
    int sockfd;
    struct sockaddr_in serv_addr;

    char buf[50], usr[30];

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
    inet_aton("127.0.0.1", &serv_addr.sin_addr);
    serv_addr.sin_port = htons(20000);

    /* With the information specified in serv_addr, the connect()
       system call establishes a connection with the server process.
    */
    if ((connect(sockfd, (struct sockaddr *)&serv_addr,
                 sizeof(serv_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        exit(0);
    }

    /* After connection, the client can send or receive messages.
       However, please note that recv() will block when the
       server is not sending and vice versa. Similarly send() will
       block when the server is not receiving and vice versa. For
       non-blocking modes, refer to the online man pages.
    */
    int n = recv(sockfd, buf, 100, 0); // recieving "LOGIN:"
    printf("%s ", buf);

    fgets(usr, 30, stdin);
    usr[strlen(usr) - 1] = '\0';
    strcpy(buf, usr);
    send(sockfd, buf, strlen(buf) + 1, 0); // sending the username
    memset(buf, 0, 100);

    n = recv(sockfd, buf, 100, 0); // recieving found status
    if (strcmp(buf, "NOT-FOUND") == 0)
        printf("Invalid username\n");
    else
    {
        while (1)
        {
            printf("Enter command: ");
            char cmd[210];
            while (fgets(buf, 49, stdin))
            {
                int len = strlen(buf);
                if (buf[len - 1] == '\n')
                {
                    buf[len - 1] = '\0';
                    send(sockfd, buf, len, 0); // sending the command
                    break;
                }
                send(sockfd, buf, 48, 0); // sending the command
            }
            if (strcmp(buf, "exit") == 0)
                break;

            memset(buf, 0, 100);
            int f = 1;
            do
            {
                n = recv(sockfd, buf, 100, 0); // recieving command output
                if (f && (strcmp(buf, "####") == 0 || strcmp(buf, "$$$$") == 0))
                    continue;
                f = 0;
                printf("%.*s", n, buf);
            } while (buf[n - 1] != '\0');
            if (strcmp(buf, "####") == 0)
                printf("Error in running command");
            else if (strcmp(buf, "$$$$") == 0)
                printf("Invalid command");
            printf("\n");
        }
    }
    // sleep(50);
    close(sockfd);
    printf("Socket Closed!  ");
    return 0;
}
