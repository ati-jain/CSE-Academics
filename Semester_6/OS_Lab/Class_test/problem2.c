// Atishay Jain
// 20CS30008
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#define MAX_INPUT 100 // assuming a user will not give more than this much characters at a time. Can increase it any time

void sig_handler(int a)
{
    printf("\b\bI am unstoppable!\n");
    fflush(stdout);
    return;
}

int main()
{
    char c[MAX_INPUT];
    signal(SIGINT, sig_handler);
    while (1)
    {
        fgets(c, MAX_INPUT - 1, stdin);
        if (strlen(c) != 2) // if not "a character" is entered
            printf("Do you speak-a my language?\n");
        else if (c[0] == 'x')
        {
            printf("Valar Morghulis\n");
            exit(0);
        }
        else if ((c[0] >= 'a' && c[0] <= 'z') || (c[0] >= 'A' && c[0] <= 'Z'))
            printf("%c\n", c[0]);
        else
            printf("Do you speak-a my language?\n");
    }
}