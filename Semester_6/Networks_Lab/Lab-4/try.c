#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    printf("Hell0");
    return (0);
}