#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void run(int n) {
    int fd = open("/proc/partb_1_20CS30008_20CS10029", O_RDWR);
    char count = (char)n;
    write(fd, &count, 1);
    for (int i = 0; i < count; i++) {
        char put = (char)(i + 1);
        int ret = write(fd, &put, sizeof(char));
        printf("\t[pid %d] Write: %d, Return: %d\n", getpid(), put, ret);
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
    printf("\n\nTest r/w:\n");
    run(5);

    return 0;
}