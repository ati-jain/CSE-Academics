/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

// Overall test case

void sort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = arr[j];
            }
        }
    }
    return;
}

int check(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 20;
    int arr[20];
    int rnd = 11;
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rnd++ % n;
    }
    int sorted = 0;
    if (check(arr, n) == 0)
    {
        sorted = 0;
    }
    else
    {
        sorted = 1;
    }
    if (sorted == 0)
    {
        sort(arr, n);
    }
    return 0;
}