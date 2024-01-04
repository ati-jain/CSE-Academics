/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// This test file checks the funciton calling and returning process and also  both boolean and algebraic expressions
int readInt(int *ep);
int printStr(char *ch);
int printInt(int number);

int a;
int b = 1;
char c;
char d = 'a';

int add(int a, int b)
{
  int ans;
  int c = 2, d, arr[10];
  int *p;
  printStr("   *** Entered into the function ***\n");
  ans = a + b;
  d = 2;
  if (a >= d)
  {
    a++;
  }
  else
  {
    c = a + b;
  }
  printStr("    *** Returned from function   ***\n");
  return ans;
}
int main()
{
  int c = 2, d, arr[10];
  int *p;
  int x, y, z;
  int eP;
  printStr("\n    Enter 1st numbers  : ");
  x = readInt(&eP);
  printStr("    Enter 2nd numbers : ");
  y = readInt(&eP);
  printStr("\n    *** Passing to the function   ***\n");
  z = add(x, y);
  printStr("\n    Sum is : ");
  printInt(z);
  printStr("\n");
  return c;
}
