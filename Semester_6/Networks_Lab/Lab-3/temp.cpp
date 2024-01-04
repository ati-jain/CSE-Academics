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
    struct sockaddr_in sa;
    char buffer[INET_ADDRSTRLEN];
    sa.sin_family = AF_INET;
    inet_aton("127.0.0.1", &sa.sin_addr);
    sa.sin_port = htons(2000);
    inet_ntop(AF_INET, &sa.sin_addr, buffer, sizeof(buffer));
    printf("address:%s:%d\n", buffer, ntohs(sa.sin_port));
    return 0;
}