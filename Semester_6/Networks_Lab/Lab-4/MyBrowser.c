#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

void toLower(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('A' - 'a');
        i++;
    }
}

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
        return;
    }
    memset((void *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // inet_aton(host, &serv_addr.sin_addr);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    if ((connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        perror("Unable to connect to server\n");
        return;
    }

    printf("Request:\n");
    sprintf(buf, "GET /%s HTTP/1.1\r\n", filename);
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    sprintf(buf, "Host: %s\r\n", host);
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    sprintf(buf, "Accept: */*\r\n");
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    time_t t = time(NULL);
    struct tm *tme = localtime(&t);
    tme->tm_mday -= 2;
    char *time = asctime(tme);
    time[strlen(time) - 1] = '\0';
    sprintf(buf, "If-Modified-Since: %s\r\n", time);
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    sprintf(buf, "Accept-language: en-us\r\n");
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    sprintf(buf, "Connection: close\r\n");
    send(sockfd, buf, strlen(buf), 0);
    printf("%s", buf);
    send(sockfd, "\r\n", 2, 0);
    printf("%s", "\r\n");

    char res[8092], headers[8092];
    int parsed = 0, len;
    char fType[50];
    int fSize = 0;
    int code;
    char ver[50];
    char status[128];

    struct pollfd fds[1];
    fds[0].fd = sockfd;
    fds[0].events = POLLIN;
    int rc = poll(fds, 1, 3000);
    if (rc == 0)
    {
        printf("Timeout!\n");
        close(sockfd);
        return;
    }
    else if (rc < 0)
    {
        printf("Error!\n");
        close(sockfd);
        return;
    }
    else if (fds[0].revents == POLLIN)
        len = recv(sockfd, res, 8091, MSG_WAITALL);
    char *prsd = strstr(res, "\r\n\r\n");
    if (prsd)
        parsed = len + res - prsd - 4;
    sprintf(headers, "%.*s", (int)(len - parsed), res);

    printf("Response: \n");
    printf("%s", headers);

    sscanf(headers, "%s %d %s", ver, &code, status);
    toLower(headers);

    char *temp = strstr(headers, "content-type");
    if (temp)
        sscanf(temp, "content-type: %s", fType);
    strtok(fType, ";\r\n");

    temp = strstr(headers, "content-length");
    if (temp)
        sscanf(temp, "content-length: %d", &fSize);

    fSize -= parsed;

    char bufFile[50];
    strcpy(bufFile, ".buffer");
    if (strcmp(fType, "application/pdf") == 0)
        strcat(bufFile, ".pdf");
    else if (strcmp(fType, "text/html") == 0)
        strcat(bufFile, ".html");
    else if (strcmp(fType, "text/plain") == 0)
        strcat(bufFile, ".txt");
    else if (strcmp(fType, "image/jpeg") == 0)
        strcat(bufFile, ".jpg");
    else if (strcmp(fType, "video/mp4") == 0)
        strcat(bufFile, ".mp4");

    FILE *fptr = fopen(bufFile, "wb");
    fwrite(prsd + 4, parsed, 1, fptr);
    while (fSize > 0)
    {
        rc = poll(fds, 1, 3000);
        if (rc == 0)
        {
            printf("Timeout!\n");
            close(sockfd);
            return;
        }
        else if (rc < 0)
        {
            printf("Error!\n");
            close(sockfd);
            return;
        }
        else if (fds[0].revents == POLLIN)
            len = recv(sockfd, res, 8091, 0);
        if (len < 0)
        {
            perror("Error in receiving");
            exit(1);
        }
        fwrite(res, len, 1, fptr);
        fSize -= len;
    }
    fclose(fptr);
    if (code == 200)
    {
        if (fork() == 0)
        {
            if (strcmp(fType, "application/pdf") == 0)
                execvp("evince", (char *[]){"evince", bufFile, NULL});
            else if (strcmp(fType, "text/html") == 0)
                execvp("firefox", (char *[]){"firefox", bufFile, NULL});
            else if (strcmp(fType, "text/plain") == 0)
                execvp("gedit", (char *[]){"gedit", bufFile, NULL});
            else if (strcmp(fType, "image/jpeg") == 0 || strcmp(fType, "image/png") == 0)
                execvp("shotwell", (char *[]){"shotwell", bufFile, NULL});
            else if (strcmp(fType, "video/mp4") == 0)
                execvp("xdg-open", (char *[]){"xdg-open", bufFile, NULL});
            else
                execvp("xdg-open", (char *[]){"xdg-open", bufFile, NULL});

            exit(0);
        }
    }
    if(code == 404)
    {
        printf("Error 404!\nNOT FOUND\n");
    }
    close(sockfd);
    printf("Connection Closed!\n");
    fflush(stdout);
}

void put(char *url)
{
    char *tUrl = strdup(url);
    strtok(url, "://");
    char *host = strtok(NULL, "/");
    char *repo = strtok(NULL, ":");
    if (repo == NULL)
    {
        strtok(tUrl, "://");
        host = strtok(NULL, ":") + 2;
        repo = "";
    }
    char *p;
    int port = 80;
    if (p = strtok(NULL, " "))
        port = atoi(p);
    char *file = strtok(NULL, "");
    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[100];

    /* Opening a socket is exactly similar to the server process */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Unable to create socket\n");
        return;
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // inet_aton(host, &serv_addr.sin_addr);
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);
    fflush(stdout);

    if ((connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        perror("Unable too connect to server\n");
        return;
    }

    long len;
    FILE *fptr = fopen(file, "rb");
    if (!fptr)
    {
        printf("File don't exist!\n");
        close(sockfd);
        return;
    }
    fseek(fptr, 0L, SEEK_END);
    len = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    printf("Request:\n");
    if (strcmp(repo, "") == 0)
        sprintf(buf, "PUT /%s HTTP/1.1\r\n", file);
    else
        sprintf(buf, "PUT /%s/%s HTTP/1.1\r\n", repo, file);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "Host: %s\r\n", host);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    sprintf(buf, "Content-language: en-us\r\n");
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    time_t t = time(NULL);
    struct tm *tme = localtime(&t);
    char *time = asctime(tme);
    time[strlen(time) - 1] = '\0';
    sprintf(buf, "Date: %s\r\n", time);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    char fType[50];
    int i = strlen(file) - 1;
    while (file[i] != '.' && i >= 0)
        i--;
    strcpy(fType, file + i + 1);
    if (strcmp(fType, "html") == 0)
        sprintf(buf, "Content-type: text/html\r\n");
    else if (strcmp(fType, "txt") == 0)
        sprintf(buf, "Content-type: text/plain\r\n");
    else if (strcmp(fType, "pdf") == 0)
        sprintf(buf, "Content-type: application/pdf\r\n");
    else if (strcmp(fType, ".jpeg") == 0 || strcmp(fType, ".jpg") == 0)
        sprintf(buf, "Content-type: image/jpeg\r\n");
    else if (strcmp(fType, ".mp4") == 0)
        sprintf(buf, "Content-type: video/mp4\r\n");

    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Content-length: %ld\r\n", len);
    printf("%s", buf);
    send(sockfd, buf, strlen(buf), 0);

    // sending blank line
    printf("\r\n");
    send(sockfd, "\r\n", 2, 0);
    int tm;
    memset(buf, 0, 100);
    while (len > 0)
    {
        tm = fread(buf, 1, 99, fptr);
        send(sockfd, buf, tm, 0);
        memset(buf, 0, 100);
        len -= tm;
        fflush(stdout);
    }

    printf("Response:\n");
    while (tm = recv(sockfd, buf, 99, 0))
        printf("%.*s", tm, buf);
    printf("Connection Closed\n");
    free(tUrl);
    fclose(fptr);
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
        strtok(req, " ");
        if (strcmp(req, "GET") == 0)
            get(strtok(NULL, ""));
        else if (strcmp(req, "PUT") == 0)
            put(strtok(NULL, ""));
        else if (strcmp(req, "") != 0 && strcmp(req, "QUIT") != 0)
            printf("Invalid Input!\n");
    } while (strcmp(req, "QUIT"));
}