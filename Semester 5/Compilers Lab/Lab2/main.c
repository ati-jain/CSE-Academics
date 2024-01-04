#include "myl.h"

int main()
{
    int in = 0;
    int i = 0;   // random value for initialisation
    float f = 0; // random value for initialisation
    do
    {
        printStr("\nSelect one: \n");
        printStr("1) Read an integer\n");
        printStr("2) Print the integer\n");
        printStr("3) Read a floating point number\n");
        printStr("4) Print the floating point number\n");
        printStr("5) Exit the program\n");
        do
        {
            printStr("Enter one: ");
            readInt(&in);
        } while (in < 1 || in > 5);

        switch (in)
        {
        case 1:
            printStr("Enter an integer: ");
            if (readInt(&i))
                printStr("Integer read successfully\n");
            else
                printStr("Operation failed!\n");
            break;

        case 2:
            printStr("Integer Value: ");
            printInt(i);
            printStr("\n");
            break;

        case 3:
            printStr("Enter a float: ");
            if (readFlt(&f))
                printStr("Float read successfully\n");
            else
                printStr("Operation failed\n");
            break;

        case 4:
            printStr("Float value: ");
            printFlt(f);
            printStr("\n");
            break;
        }
    } while (in != 5);
    return 0;
}