/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

// Loops and If-Else Block

int main()
{
    float a = 4;
    int b = 5;
    int i;
    i = a * b;
    while (i >= 0)
    {
        if (i % 2 == 0)
        {
            i = i - 2;
        }
        else
        {
            i--;
        }
    }
    int flag;
    flag = 0;
    int j;
    for (j = 0; j < a; j++)
    {
        int k;
        for (k = b; k >= i; k++)
        {
            if (j == k)
            {
                flag++;
            }
            else
            {
                flag = flag - 2;
            }
        }
    }
    return 0;
}