/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

// Relational, Boolean, Unary Operator

int main()
{
    int a = 5;
    int b = -a;
    int c = ~b;
    int d = c++;
    --d;
    a = !c;
    if(a < b)
        c = 1;
    if(a > c || d >= a)
        b = a;
    else if(a == 4 && d <= c)
        a = 0;
    else
        d = 5;
    return 0;
}