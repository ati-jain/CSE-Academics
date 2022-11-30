/*
Atishay Jain - 20CS30008
Suvvari Venkata Sai - 20CS10067
*/
enum Grades{F, E, D, C, B, A};

auto int a;

struct stu
{
    unsigned int roll;
    float marks;
    enum Grades g;
};

inline int func(int *restrict a, volatile int b)
{
    static int si = 4;
    extern int ei;
    register int ri;
    return 0;
}

void mergeSort(struct stu arr[], int l, int r)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    int i = 0, j = 0, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    struct stu L[n1], R[n2];

    for (; i < n1; ++i)
        L[i] = arr[l + i];

    for (; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].marks <= R[j].marks)
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

int main()
{
    unsigned long ul = 852852;
    char s[5] = "Ati";
    float f = (int)(567.345);
    f = (float)f;

    const int n = 10;
    short s = sizeof(struct stu);
    double d = 523.65e-1;
    d--;
    d /= n;
    d *= 5;
    int t = 6;
    t <<= 1;
    t %= 5;
    int n2 = func(0, 1);

    struct stu list[n];

    for (int i = 0; i < n * 2; i++)
    {
        if (i == n)
            continue;
        if (i > n)
            goto end_loop;
        list[i].roll = i * 10;
        d = (d * i) / 100;
        while (d >= 100)
            d -= 100;

        list[i].marks = d;
        switch (i)
        {
        case 0:
        case 1:
            list[i].g = F;
            break;

        case 2:
            list[i].g = E;
            break;

        case 3:
            list[i].g = D;
            break;

        case 4:
            list[i].g = C;
            break;

        case 5:
            list[i].g = B;
            break;

        case 6:
        case 7:
        case 8:
            list[i].g = A;
            break;

        default:
            list[i].g = B;
        }
    }
end_loop:
    mergeSort(list, 0, n);
}