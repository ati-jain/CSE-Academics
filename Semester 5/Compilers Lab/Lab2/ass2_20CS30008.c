#include "myl.h"
#define BUFF 50
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define M (int)1E6

int printStr(char *str)
{
    int len = -1;
    while (str[++len] != '\0') // calculating the length of the string
        ;
    __asm__ __volatile__( // assembly language code for printing
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        : "S"(str), "d"(len));
    return len;
}

int readInt(int *n)
{
    char input[BUFF], zero = '0';
    int len = -1;

    __asm__ __volatile__( // assembly language code for reading
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(input), "d"(BUFF));

    if (len <= 0)
        return ERR;

    int sign = 1, index = 0;
    long long ans = 0;

    while (input[index] == ' ') // if there are some spaces before the integer, we will ignore them
        index++;

    if (input[index] == '-') // if the integer is negative
    {
        sign = -1;
        index++;
    }

    else if (input[index] == '+')
        index++;

    // if there is a space in the input stream, the we will take the first input only
    // if there is a ".", then we will take the integral part only
    while (input[index] != ' ' && input[index] != '\n' && input[index] != '.')
    {
        if (input[index] < '0' || input[index] > '9') // if the input is invalid
            return ERR;
        ans *= 10;
        ans += sign * (int)(input[index] - zero);
        if (ans > INT_MAX || ans < INT_MIN) // if the input is out of bound, then we will return error
            return ERR;
        index++;
    }

    *n = (int)ans; // assigning
    return OK;
}

int printInt(int n)
{
    // if n == INT_MIN; then we can't do n = -n
    char integer[BUFF] = "-2147483648", zero = '0', temp;
    int len = 0, neg = 0;
    if (n == INT_MIN)
        len = 11; // length of "-2147483648"
    else if (n == 0)
        integer[len++] = zero;
    else
    {
        if (n < 0)
        {
            integer[len++] = '-';
            n = -n;
            neg = 1; // so the integer part will start from index 1 in the array
        }
        while (n)
        {
            integer[len++] = zero + n % 10; // populating the array
            n /= 10;
        }

        for (int j = neg; j < (len + neg) / 2; j++) // reversing the array
        {
            temp = integer[j];
            integer[j] = integer[len - 1 - j + neg];
            integer[len - 1 - j + neg] = temp;
        }
    }
    integer[len] = '\0';

    if (len == 0)
        return ERR;

    return printStr(integer);
}

int readFlt(float *f)
{
    char input[BUFF];
    int len;

    __asm__ __volatile__( // assembly language code for reading
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"
        "syscall \n\t"
        : "=a"(len)
        : "S"(input), "d"(BUFF));

    if (len <= 0)
        return ERR;

    int sign = 1, index = 0, exp = 0, esign = 1;
    float ans = 0;

    while (input[index] == ' ') // if there are some spaces before the integer, we will ignore them
        index++;

    if (input[index] == '-') // if the float is negative
    {
        sign = -1;
        index++;
    }
    else if (input[index] == '+')
        index++;

    // if there is a space in the input stream, the we will take the first floating number   only
    // if there is a ".", then we will go for reading the fractional part
    // if there is an "e" or "E", then we will go for reading the exponents
    while (input[index] != ' ' && input[index] != '.' && input[index] != 'E' && input[index] != 'e' && input[index] != '\n')
    {
        if (input[index] < '0' || input[index] > '9') // if the input is invalid
            return ERR;
        ans *= 10;
        ans += (int)(input[index] - '0');
        index++;
    }

    if (input[index] == '.')
    {
        index++;
        float shift = 10;

        while (input[index] != ' ' && input[index] != '\n' && input[index] != 'E' && input[index] != 'e')
        {
            if (input[index] < '0' || input[index] > '9') // if the input is invalid
                return ERR;
            float curr = (float)(input[index] - '0');
            curr /= shift;
            ans += curr; // adding the fractional part
            shift *= 10;
            index++;
        }
    }

    if (input[index] == 'E' || input[index] == 'e') // for reading exponents
    {
        index++;
        if (input[index] == '-') // sign of exponent
        {
            esign = -1;
            index++;
        }
        else if (input[index] == '+')
            index++;

        while (input[index] != ' ' && input[index] != '\n')
        {
            if (input[index] < '0' || input[index] > '9') // if the input is invalid
                return ERR;

            exp *= 10;
            exp += (int)(input[index] - '0');
            index++;
        }
    }

    for (int i = 1; i <= exp; i++) // handling the exponent
    {
        if (esign == 1)
            ans *= 10;
        else
            ans /= 10;
    }

    *f = sign * ans;
    return OK;
}

int printFlt(float f)
{
    int len = 0;
    if (f < 0) // if f is negative
    {
        len += printStr("-");
        f = -f;
    }

    int i_part = (int)f;
    len += printInt(i_part); // printing the integral part

    len += printStr("."); // printing decimal

    float d_part = f - i_part;
    int dec = d_part * M;
    len += printInt(dec); // printing fractinal part till 6 digits

    if (len == 0)
        return ERR;

    return len;
}