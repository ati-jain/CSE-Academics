/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This testfile checks the functioning of the library functions  printInt  and printStr
int readInt(int *ep);
int printInt(int number);
int printStr(char *ch);

int main()
{
    int a1;
    int b;
    int *e;

    printStr("\n        -------------------------------------------------------\n        --                                                 --\n        --         Print first 20 natural numbers           --\n        --                   (loop)                         --\n        --                                                  --\n        -----------------------------------------------------------------\n\n");

    b = 1;
    e = &b;

    printStr("        ");
    for (a1 = 0; a1 < 20; a1++)
    {
        printInt(b);
        printStr(" ");
        b = b + 1;
    }

    return 0;
}