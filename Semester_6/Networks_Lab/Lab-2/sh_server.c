/*
Name: Atishay Jain
Roll No.: 20CS30008
*/
/*
            NETWORK PROGRAMMING WITH SOCKETS

In this program we illustrate the use of Berkeley sockets for interprocess
communication across the network. We show the communication between a server
process and a client process.


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* THE SERVER PROCESS */

int sendTCP(char *buftosend, int sockfd)
{
    int i = 0;
    char buf[50];
    while (i <= strlen(buftosend))
    {
        int k = 0;
        int j;
        for (j = i; j <= strlen(buftosend) && j < i + 49; j++)
        {
            buf[k] = buftosend[j];
            k++;
        }
        if (buf[k - 1] == '\0')
        {
            send(sockfd, buf, k, 0);
        }
        else
        {
            send(sockfd, buf, strlen(buf), 0);
        }
        i += 49;
    }
    return 0;
}

int main()
{
    int sockfd, newsockfd; /* Socket descriptors */
    int clilen;
    struct sockaddr_in cli_addr, serv_addr;

    int i;
    char *buf = (char *)malloc(50 * sizeof(char)); /* We will use this buffer for communication */

    /* The following system call opens a socket. The first parameter
       indicates the family of the protocol to be followed. For internet
       protocols we use AF_INET. For TCP sockets the second parameter
       is SOCK_STREAM. The third parameter is set to 0 for user
       applications.
    */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Cannot create socket\n");
        exit(0);
    }

    /* The structure "sockaddr_in" is defined in <netinet/in.h> for the
       internet family of protocols. This has three main fields. The
       field "sin_family" specifies the family and is therefore AF_INET
       for the internet family. The field "sin_addr" specifies the
       internet address of the server. This field is set to INADDR_ANY
       for machines having a single IP address. The field "sin_port"
       specifies the port number of the server.
    */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(20000);

    /* With the information provided in serv_addr, we associate the server
       with its port using the bind() system call.
    */
    if (bind(sockfd, (struct sockaddr *)&serv_addr,
             sizeof(serv_addr)) < 0)
    {
        printf("Unable to bind local address\n");
        exit(0);
    }

    listen(sockfd, 5); /* This specifies that up to 5 concurrent client
                  requests will be queued up while the system is
                  executing the "accept" system call below.
               */
    printf("server running...\n");
    /* In this program we are illustrating a concurrent server -- one
       which forks to accept multiple client connections concurrently.
       As soon as the server accepts a connection from a client, it
       forks a child which communicates with the client, while the
       parent becomes free to accept a new connection. To facilitate
       this, the accept() system call returns a new socket descriptor
       which can be used by the child. The parent continues with the
       original socket descriptor.
    */
    while (1)
    {

        /* The accept() system call accepts a client connection.
           It blocks the server until a client request comes.

           The accept() system call fills up the client's details
           in a struct sockaddr which is passed as a parameter.
           The length of the structure is noted in clilen. Note
           that the new socket descriptor returned by the accept()
           system call is stored in "newsockfd".
        */
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr,
                           &clilen);

        if (newsockfd < 0)
        {
            printf("Accept error\n");
            exit(0);
        }

        /* Having successfully accepted a client connection, the
           server now forks. The parent closes the new socket
           descriptor and loops back to accept the next connection.
        */
        if (fork() == 0)
        {

            /* This child process will now communicate with the
               client through the send() and recv() system calls.
            */
            close(sockfd); /* Close the old socket since all
                      communications will be through
                      the new socket.
                   */

            /* We initialize the buffer, copy the message to it,
               and send the message to the client.
            */

            strcpy(buf, "LOGIN:");
            send(newsockfd, buf, strlen(buf) + 1, 0);
            memset(buf, 0, 50);

            /* We again initialize the buffer, and receive a
               message from the client.
            */
            recv(newsockfd, buf, 100, 0); // recieved the username
            FILE *fptr = fopen("./users.txt", "r");
            int fnd = 0;
            char usr[30];
            while (!feof(fptr)) // searching for the username in data
            {
                fscanf(fptr, "%s", usr);
                if (strcmp(buf, usr) == 0)
                {
                    strcpy(buf, "FOUND");
                    send(newsockfd, buf, strlen(buf) + 1, 0);
                    memset(buf, 0, 50);
                    fnd = 1;
                    break;
                }
            }
            if (fnd == 0) // if not found
            {
                strcpy(buf, "NOT-FOUND");
                send(newsockfd, buf, strlen(buf) + 1, 0);
                memset(buf, 0, 50);
            }
            while (1)
            {
                int n;
                char cmd[210] = "";
                do
                {
                    n = recv(newsockfd, buf, 50, 0); // recieving command
                    buf[n] = '\0';
                    strcat(cmd, buf);
                } while (buf[n - 1] != '\0');

                // printf("cmd = %s", cmd);
                if (strcmp(cmd, "exit") == 0)
                    break;

                int l = strlen(cmd);
                while (l > 0 && cmd[l - 1] == ' ')
                {
                    l--;
                    cmd[l] = '\0';
                }
                char dir[210];
                int s = 0;
                while (cmd[s] == ' ')
                    s++;
                if (n > 3 && cmd[s + 0] == 'p' && cmd[s + 1] == 'w' && cmd[s + 2] == 'd' && (cmd[s + 3] == '\0' || cmd[s + 3] == ' '))
                {
                    // printf("executing pwd\n");
                    if (getcwd(dir, 200))
                    {
                        int i = 0;
                        char buf[50];
                        while (i <= strlen(dir))
                        {
                            int k = 0;
                            int j;
                            for (j = i; j <= strlen(dir) && j < i + 49; j++)
                            {
                                buf[k] = dir[j];
                                k++;
                            }
                            if (buf[k - 1] == '\0')
                            {
                                send(newsockfd, buf, k, 0);
                            }
                            else
                            {
                                send(newsockfd, buf, strlen(buf), 0);
                            }
                            i += 49;
                        }
                    }
                    else
                        perror("getcwd() error.");
                }
                else if (cmd[s + 0] == 'd' && cmd[s + 1] == 'i' && cmd[s + 2] == 'r')
                {
                    // printf("executing dir\n");
                    if (strlen(cmd + s) == 3)
                        strcpy(dir, ".");
                    else if (cmd[s + 3] == ' ')
                    {
                        int i = s + 4;
                        while (cmd[i] == ' ')
                            i++;
                        int j = 0;
                        while (cmd[i + j] != ' ' && cmd[i + j] != '\0')
                        {
                            dir[j] = cmd[i + j];
                            j++;
                        }
                        dir[j] = '\0';
                    }
                    else
                    {
                        send(newsockfd, "$$$$", strlen("$$$$") + 1, 0);
                        continue;
                    }

                    DIR *d;
                    if (d = opendir(dir))
                    {
                        struct dirent *entry;
                        // send(newsockfd, entry->d_name, strlen(entry->d_name) + 1, 0);
                        memset(buf, 0, 50);
                        while (entry = readdir(d))
                        {
                            strcpy(cmd, entry->d_name);
                            strcat(cmd, "\t");
                            send(newsockfd, cmd, strlen(cmd), 0);
                        }
                        send(newsockfd, "\0", 1, 0);
                    }
                    closedir(d);
                }
                else if (cmd[s + 0] == 'c' && cmd[s + 1] == 'd')
                {
                    // printf("executing cd\n");
                    if (cmd[s + 2] == '\0')
                        send(newsockfd, "####", strlen("####") + 1, 0);

                    int i = s + 2;
                    while (cmd[i] == ' ')
                        i++;
                    if (i == s + 2)
                        send(newsockfd, "$$$$", strlen("$$$$") + 1, 0);
                    if (chdir(cmd + i) == -1)
                        send(newsockfd, "####", strlen("####") + 1, 0);
                    send(newsockfd, "Done", strlen("Done") + 1, 0);
                    memset(buf, 0, 50);
                }
                else // invalid command
                {
                    send(newsockfd, "$$$$", strlen("$$$$") + 1, 0);
                    memset(buf, 0, 50);
                }
            }
            close(newsockfd);
            exit(0);
        }

        close(newsockfd);
    }
    return 0;
}