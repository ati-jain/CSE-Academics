/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

// Declarations, Assignments and Function calls

float add(float a, float b);
int fibb(int n);

int main()
{
    int a = 5;
    int b = 10;
    b = a + b;
    int fib = fibb(b);
    int fib2;
    fib2 = fibb(fib);
}

float add(float a, float b)
{
    return a + b;
}

int fibb(int n)
{
    if (n <= 1)
        return n;
    else
        return add(fibb(n - 1), fibb(n - 2));
}