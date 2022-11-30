/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This test file checks the library functions readInt,printStr,printInt

int readInt(int *eP);
int printStr(char *c);
int printInt(int i);

int main()
{

  printStr("Enter the value of N less than 30: ");
  int i, ep;
  i = readInt(&ep);
  printStr("\nEntered value was: ");
  printInt(i);

  printStr("\n\nThe first  ");
  printInt(i);
  printStr(" fibonacci numbers are :\n\n        ");

  int a = 0, b = 1, c = 0;
  int j;

  if (i > 0)
    printInt(a);
  printStr(" ");
  if (i > 1)
    printInt(b);
  printStr(" ");

  for (j = 2; j < i; j++)
  {
    c = a + b;
    printInt(c);
    printStr(" ");
    a = b;
    b = c;

    int r = j / 10;
    if (r * 10 == j)
    {
      printStr("\n        ");
    }
  }

  printStr("\n");
  return;
}