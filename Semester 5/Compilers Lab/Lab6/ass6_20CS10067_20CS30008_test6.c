/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This test file checks the library functions printStr,readInt,printInt

int printStr(char *ch);
int readInt(int *ep);
int printInt(int number);

int pown(int a, int b)
{
  int ans;
  if (b == 0)
    ans = 1;
  else if (b == 1)
    ans = a;
  else
    ans = a * pown(a, b - 1);
  return ans;
}

int main()
{
  int i, j = 5, c;
  int *b = &c;

  printStr("      Enter the Base     : ");
  i = readInt(b);
  printStr("      Enter the Eexponent : ");
  j = readInt(b);
  c = pown(i, j);
  printStr("\n\n      The value of ");
  printInt(i);
  printStr("^");
  printInt(j);
  printStr(" is : ");
  printInt(c);
  printStr("\n");
  return 0;
}