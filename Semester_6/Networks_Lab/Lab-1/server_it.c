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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFSIZE 20

/* THE SERVER PROCESS */

int isNum(char c)
{
    if ((c <= '9' && c >= '0') || c == '.')
        return 1;
    return 0;
}
int isOp(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return 1;
    return 0;
}
double eval(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return (int)a % (int)b;
    }
    return b;
}

int main()
{
    int sockfd, newsockfd; /* Socket descriptors */
    int clilen;
    struct sockaddr_in cli_addr, serv_addr;

    int i;
    char buf[100]; /* We will use this buffer for communication */

    /* The following system call opens a socket. The first parameter
       indicates the family of the protocol to be followed. For internet
       protocols we use AF_INET. For TCP sockets the second parameter
       is SOCK_STREAM. The third parameter is set to 0 for user
       applications.
    */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Cannot create socket\n");
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
        perror("Unable to bind local address\n");
        exit(0);
    }

    listen(sockfd, 5); /* This specifies that up to 5 concurrent client
                  requests will be queued up while the system is
                  executing the "accept" system call below.
               */
    printf("listening to port %d...\n", serv_addr.sin_port);
    /* In this program we are illustrating an iterative server -- one
       which handles client connections one by one.i.e., no concurrency.
       The accept() system call returns a new socket descriptor
       which is used for communication with the server. After the
       communication is over, the process comes back to wait again on
       the original socket descriptor.
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
            perror("Accept error\n");
            exit(0);
        }
        printf("Connected!\n");

        while (1)
        {

            /* We now receive a message from the client. For this example
               we make an assumption that the entire message sent from the
               client will come together. In general, this need not be true
               for TCP sockets (unlike UDPi sockets), and this program may not
               always work (for this example, the chance is very low as the
               message is very short. But in general, there has to be some
               mechanism for the receiving side to know when the entire message
              is received. Look up the return value of recv() to see how you
              can do this.
            */
            int len;
            char trm[20];
            double stack[3];
            int tp = 0, br = 0;
            int nw = 1;
            int tl = 0;
            char op = '.', opbr;
            do
            {
                len = recv(newsockfd, buf, BUFFSIZE, 0);
                if (len <= 0)
                    break;
                // printf("%.*s", len, buf);
                for (int i = 0; i < len; i++)
                {
                    // printf("%c", buf[i]);
                    if (nw && buf[i] == '-')
                    {
                        trm[tl++] = '-';
                        nw = 0;
                    }
                    else if (isNum(buf[i]))
                    {
                        trm[tl++] = buf[i];
                        nw = 0;
                    }
                    else if (isOp(buf[i]))
                    {
                        trm[tl] = '\0';
                        if (tl)
                            stack[br + tp++] = atof(trm);
                        if (tp > 1)
                        {
                            stack[br + tp - 2] = eval(stack[br + tp - 2], stack[br + tp - 1], op);
                            tp--;
                        }
                        tl = 0;
                        op = buf[i];
                        nw = 1;
                    }
                    else if (buf[i] == '(')
                    {
                        br = 1;
                        tp = 0;
                        opbr = op;
                        nw = 1;
                    }
                    else if (buf[i] == ')')
                    {
                        trm[tl] = '\0';
                        stack[br + tp++] = atof(trm);
                        if (tp > 1)
                        {
                            stack[br + tp - 2] = eval(stack[br + tp - 2], stack[br + tp - 1], op);
                            tp--;
                        }
                        tl = 0;
                        br = 0;
                        // printf("%lf  %lf", stack[tp - 1], stack[tp]);
                        stack[tp - 1] = eval(stack[tp - 1], stack[tp], opbr);
                    }
                }
            } while (buf[len - 1] != '\0');

            if (len <= 0) // when the client is disconnected
                break;
            if (tl > 0)
            {
                trm[tl] = '\0';
                stack[br + tp++] = atof(trm);
                stack[tp - 2] = eval(stack[tp - 2], stack[tp - 1], op);
            }
            /* We initialize the buffer, copy the message to it,
                and send the message to the client.
            */
            // strcpy(buf, "message from server");
            sprintf(buf, "%lf", stack[0]);
            send(newsockfd, buf, strlen(buf) + 1, 0);
            stack[0] = 0;
            printf("Calculated\n");
        }
        printf("Disconnected!\n");
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}
