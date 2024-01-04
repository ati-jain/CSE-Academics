#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void get(char *url)
{
    strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *filename = strtok(NULL, ":");
    char *p = strtok(NULL, "");
    int port = 80;
    if (p)
        port = atoi(p);

    int sockfd;
    struct sockaddr_in serv_addr;

    int i;
    char buf[100];

    /* Opening a socket is exactly similar to the server process */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }

    memset((void *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // inet_aton(host, &serv_addr.sin_addr);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    if ((connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        exit(0);
    }

    sprintf(buf, "GET /%s HTTP/1.1\n", filename);
    // printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Host: localhost\n");
    // printf("%s", buf);
    // sprintf(buf, "Host: %s\n", host);
    send(sockfd, buf, strlen(buf), 0);

    // completing the get request
    send(sockfd, "\n", 2, 0);
    // printf("\n");

    char res[512];
    // char *filercvd = NULL;
    // char *filercvd = (char *)calloc(10000, sizeof(char));
    int left, len;
    // char *type;
    // char *stype;
    char fType[50];
    int fSize;
    // char *end;
    len = recv(sockfd, res, 511, 0);
    // while (len = recv(sockfd, res, 511, 0))
    // {
    //     // filercvd = realloc(filercvd, t + len);
    //     // strncpy(filercvd + t, res, len);
    //     strncat(filercvd, res, len);
    //     // if (type)
    //     //     break;
    //     // t += len;
    //     // printf("%.*s", len, res);
    // }

    // printf("\n\n%d\n\n", len);
    // printf("\n\n%s", filercvd);

    // type = strstr(filercvd, "Content-Type: ");
    sscanf(strstr(res, "Content-type"), "%s", fType);
    // if (type == NULL)
    //     type = strstr(filercvd, "Content-type");
    // end = strstr(type, "\r\n");
    // type += strlen("Content-type: ");
    sscanf(strstr(res, "Content-Length"), "Content-Length: %d", &fSize);
    // end = strstr(type, "\r\n");
    // printf("Type = %s", type);
    // sprintf(cType, "%.*s\n", (int)(end - type), type);
    // sprintf(cType, "%s", stype);
    // filercvd = strstr(end + 2, "\r\n\r\n");
    // filercvd += 4;
    // printf("FILE = \n%s", filercvd);
    // printf("%d", strlen(filercvd));
    // // // printf("%.*s\n\n", (int)(end - filercvd), filercvd);
    // // filercvd = end + strlen("\r\n\r\n");
    FILE *fptr = fopen("temp.pdf", "wb");
    while (fSize > 0)
    {
        len = recv(sockfd, res, 511, 0);
        if (len < 0)
        {
            perror("Error in receiving");
            exit(1);
        }
        fwrite(res, len, 1, fptr);
        fSize -= len;
    }
    fclose(fptr);
    // char **argv = (char **)malloc(sizeof(char *) * 2);
    // // for(int i = 0;  i< n; i++)
    // //     argv[i] = strdup()
    // argv[0] = strdup("xdg-open");
    // argv[1] = strdup("temp.pdf");
    // if (fork() == 0)
    // {
    //     execvp("xdg-open", argv);
    // }
    // printf("%s", filercvd);
    printf("Connection Closed!\n");
    close(sockfd);
}

void put(char *url)
{
    char *t = strdup(url);
    strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *repo = strtok(NULL, ":");
    if (repo == NULL)
    {
        strtok(t, "://");
        host = strtok(NULL, ":") + 2;
        repo = "";
    }
    char *p;
    int port = 80;
    if (p = strtok(NULL, " "))
        port = atoi(p);
    char *file = strtok(NULL, "");
    free(t);
    int sockfd;
    struct sockaddr_in serv_addr;
    printf("host = %s, repo = %s, port = %s, file = %s", host, repo, p, file);
    int i;
    char buf[100];

    /* Opening a socket is exactly similar to the server process */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        exit(0);
    }
    host = "127.0.0.1";
    serv_addr.sin_family = AF_INET;
    // inet_aton(host, &serv_addr.sin_addr);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    if ((connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        perror("Unable too connect to server\n");
        exit(0);
    }

    long len;
    FILE *fptr = fopen(file, "r");
    fseek(fptr, 0L, SEEK_END);
    len = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    sprintf(buf, "PUT /%s/%s HTTP/1.1\n", repo, file);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Host: %s\n", host);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Content-length: %ld\n", len);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    // sending blank line
    send(sockfd, "\n", 1, 0);
    printf("\n");

    memset(buf, 0, 100);
    while (fgets(buf, 99, fptr))
    {
        send(sockfd, buf, strlen(buf), 0);
        printf("%s", buf);
        memset(buf, 0, 100);
    }
    // terminating the put request
    // send(sockfd, "", 1, 0);

    close(sockfd);
}

int main()
{
    char req[1024];
    do
    {
        printf("MyBrowser> ");
        fgets(req, 1024, stdin);
        req[strlen(req) - 1] = '\0';
        // scanf("%[^\n]s", req);
        // getchar();
        strtok(req, " ");
        if (strcmp(req, "GET") == 0)
        {
            get(strtok(NULL, ""));
        }
        else if (strcmp(req, "PUT") == 0)
        {
            put(strtok(NULL, ""));
        }
    } while (strcmp(req, "QUIT"));
}