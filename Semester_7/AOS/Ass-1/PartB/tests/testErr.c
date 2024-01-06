#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void run(int val[], int n) {
    int fd = open("/proc/partb_1_20CS30008_20CS10029", O_RDWR);
    printf("fd: %d\n", fd);
    char ctr = (char)(n);
    int ret;
    if ((ret = write(fd, &ctr, 1)) < 0) {
        printf("Error, return value: %d\n", ret);
        return;
    }
    int fd1 = open("/proc/partb_1_20CS30008_20CS10029", O_RDWR);
    if (fd1 < 0) {
        printf("Error, return value: %d\n", fd1);
    }
    for (int i = 0; i < ctr; i++) {
        int ret = write(fd, &val[i], sizeof(int));
        printf("[pid %d] Write: %d, Return: %d\n", getpid(), val[i], ret);
        usleep(100);
    }
    for (int i = 0; i < ctr; i++) {
        int out;
        int ret = read(fd, &out, sizeof(int));
        printf("[pid %d] Read: %d, Return: %d\n", getpid(), out, ret);
        usleep(100);
    }
    close(fd);
}

int main() {
    printf("\n\nTest multiple file descriptors:\n");
    int val_p[] = {4000, -5, 6, 127};

    run(val_p, sizeof(val_p) / sizeof(int));

    return 0;
}