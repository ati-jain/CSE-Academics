/* Compilers Assignment - 4 */
/* Atishay Jain (20CS30008) */
/* Suvvari Venkata Sai Suvvari (20CS10067) */

// Arrays and Pointers

int main()
{
    int arr1[10];
    int *arrp;
    int ind[10][10];
    float f[5];
    float **arrf;
    float arr3[20][20][20];
    int i;
    for(i = 0; i < 20; i++)
    {
        int j;
        for(j = 0; j < 20; j++)
        {
            int k;
            for(k = 0; k < 20; k++)
            {
                arr3[i][j][k] = i + j + k;
            }
        }
    }
    char str[20];
    char *name = "Atishay Jain";
    *arrf = f;
    arr1[2] = ind[1][3];
    arrp = arr1;
    arrp[0] = arr1[1];
    f[3] = arr1[4];
    return 0;
}