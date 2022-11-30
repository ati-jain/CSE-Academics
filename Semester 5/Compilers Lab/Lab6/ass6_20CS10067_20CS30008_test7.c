/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This test file checks the library functions printStr,readInt,printInt

int printStr(char *ch);
int printInt(int number);
int readInt(int *ep);

int main()
{
    int ep;
    printStr("       Enter the size of triangle ");

    int b, n, i, j;
    n = readInt(&ep);

    for (i = 0; i < 2 * n - 1; i++)
    {
        printStr("\n        ");
        for (j = 0; j <= i; j++)
        {
            printStr("*");
        }
    }
    return 0;
}