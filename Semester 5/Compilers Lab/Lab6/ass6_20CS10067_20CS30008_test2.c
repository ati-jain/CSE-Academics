/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This testfile checks the functioning of the library functions  readInt,printInt, and printStr
int readInt(int *ep);
int printInt(int number);
int printStr(char *ch);

// return an int value
int test(int *a)
{
    return a;
}

int main()
{
    int a;
    int b;
    b = 3;
    int *e;
    e = &b;

    // checking printStr() and printSInt()
    printStr("\n\n       Testing this function :\n        int test(int *a)    \n");
    printStr("\n        Value passed to function: ");
    printInt(b);
    printStr("\n");

    a = test(b);
    printStr("\n        The function returns the following address: ");
    printInt(a);
    printStr("\n");

    printStr("\nEnter an int number : ");
    b = readInt(e);
    printStr("The integer read was : ");
    printInt(b);
    printStr("\n");

    return 0;
}