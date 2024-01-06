#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

typedef struct struct_client_info
{
    struct sockaddr_in client_addr;
    int sockfd;
    int sleep_time;
} client_info;

int total_sleep;
pthread_mutex_t lock;

void *handle_request(void *arg)
{
    client_info *info = (client_info *)arg;

    int sleep_time = info->sleep_time;

    printf("Sleeping for %d seconds\n", info->sleep_time); fflush(stdout);
    sleep(info->sleep_time);

    pthread_mutex_lock(&lock);
    total_sleep += info->sleep_time;
    pthread_mutex_unlock(&lock); 

    // Generate random data
    char random_data[4] = "free";

    // Send data back to client
    sendto(info->sockfd, (const char *)random_data, strlen(random_data), 0, (const struct sockaddr *)&info->client_addr, sizeof(info->client_addr));

    printf("Slept for %d seconds in total till now\n\n", total_sleep); fflush(stdout);

    free(info);
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Only 1 argument required (port number)\n");
        exit(EXIT_FAILURE);
    }
    int sockfd, n;
    int _port = atoi(argv[1]);
    struct sockaddr_in servaddr, cliaddr;

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Socket Creation Failed\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(_port);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Unable to bind the socket to local address\n");
        exit(EXIT_FAILURE);
    }

    printf("\nServer running on port %d....\n", _port); fflush(stdout);
    char buf[100];
    socklen_t clilen;
    pthread_t thread_id;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init has failed\n");
        return 1;
    }

    while (1)
    {
        clilen = sizeof(cliaddr);

        n = recvfrom(sockfd, (char *)buf, 100, 0, (struct sockaddr *)&cliaddr, &clilen);

        int sleep_time = *(int *)buf;

        printf("Received sleep time: %d\n", sleep_time); fflush(stdout);

        client_info *info = malloc(sizeof(client_info));
        info->client_addr = cliaddr;
        info->sockfd = sockfd;
        info->sleep_time = sleep_time;

        pthread_create(&thread_id, NULL, handle_request, (void *)info);
        pthread_detach(thread_id);
        // free(info);
    }
    pthread_mutex_destroy(&lock);
    close(sockfd);
    return 0;
}