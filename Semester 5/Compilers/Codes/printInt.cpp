#include <limits.h>
#define BUFF 20

void print(int n)
{
    char buff[BUFF] = "-2147483648", zero = '0', temp;
    int i = 0, neg = 0;
    if (n == INT_MIN)
        i = 11;
    else if (n == 0)
        buff[i++] = zero;
    else
    {
        if (n < 0)
        {
            buff[i++] = '-';
            n = -n;
            neg = 1;
        }
        while (n)
        {
            buff[i++] = zero + n % 10;
            n /= 10;
        }

        for (int j = neg; j < (i + neg) / 2; j++)
        {
            temp = buff[j];
            buff[j] = buff[i - 1 - j + neg];
            buff[i - 1 - j + neg] = temp;
        }
    }
    buff[i] = '\0';

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(buff), "d"(i + 1));

    return;
}