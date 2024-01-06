#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void run(int val[], int n) {
    int fd = open("/proc/partb_1_20CS30008_20CS10029", O_RDWR);
    char count = (char)n;
    write(fd, &count, 1);
    for (int i = 0; i < count; i++) {
        int ret = write(fd, &val[i], sizeof(int));
        printf("\t[pid %d] Write: %d, Return: %d\n", getpid(), val[i], ret);
        usleep(100);
    }
    for (int i = 0; i < count; i++) {
        int out;
        int ret = read(fd, &out, sizeof(int));
        printf("\t[pid %d] Read: %d, Return: %d\n", getpid(), out, ret);
        usleep(100);
    }
    close(fd);
}

int main() {
    printf("\n\nTest concurrency:\n");
    int val_p[] = {4000, -5, 6, 127};

    int val_c[] = {9282, 0, -1, 98};

    int pid = fork();
    if (pid == 0) {
        run(val_c, 4);
    } else {
        run(val_p, 4);
        wait(NULL);
    }
    
    return 0;
}