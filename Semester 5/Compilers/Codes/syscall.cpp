#include <unistd.h>
#define LEN 8

int main()
{
    char str[LEN] = "Atishay";
    write(1, str, LEN);// wrtie(1 = file pointer to write; 1 for stdout(terminal), str = string pointer, LEN = string length)
    _exit(0);
}