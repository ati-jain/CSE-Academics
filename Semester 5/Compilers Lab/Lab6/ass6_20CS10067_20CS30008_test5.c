/* Compilers Assignment - 6 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */
// test file to check basic statements, expression, readInt and printInt library
// functions created in assignment 2
// also checks the recursive fibonacci function to check the function call and return methodology

int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int func2(int a)
{
  return a;
}

int func(int a)
{
  int b = a;
  int c = func2(b);
  return c;
}

int main()
{
  int a = 5;
  int ans = func(a);
  printInt(ans);
}