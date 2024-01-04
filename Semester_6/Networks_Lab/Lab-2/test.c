#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
int main()
{
    char buf[100] = "Here";
    // memset(buf, 0, 100);
    // DIR *d = opendir(".");
    // if(d)
    //     printf("%s", buf);
    // else
    //     printf("not");
    // printf("%.*s", 3, buf);
    // char source[] = "abcdefthijklmn";
    // char target[100] = "asasdfasdfkas;dflkj";

    // snprintf(target, sizeof target, "%.10s", source);
    // printf("%s", target);
    // snprintf(target, sizeof target, "%.10s", source + 10);
    // printf("%s", target);
    fgets(buf, 30, stdin);
    printf("%s", buf);
    fgets(buf, 30, stdin);
    printf("%s", buf);
    return 0;
}