#include "goodmalloc.h"
#include <stdio.h>
#include <time.h>
using namespace std;

void mergesort(Element *lst, int n)
{
    funcinit();
    if (n == 1)
    {
        freeElem();
        return;
    }
    int mid = n / 2;
    Element *lst1 = lst;
    Element *lst2 = accessElem(lst, mid);
    mergesort(lst1, mid);
    mergesort(lst2, n - mid);
    Element *temp = createList(n, temp);
    if (temp == NULL)
    {
        printf("createList error: Not enough memory\n");
        exit(1);
    }
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (accessElem(lst1, i)->value < accessElem(lst2, j)->value)
        {
            assignVal(temp, k, accessElem(lst1, i)->value);
            i++;
        }
        else
        {
            assignVal(temp, k, accessElem(lst2, j)->value);
            j++;
        }
        k++;
    }
    while (i < mid)
    {
        assignVal(temp, k, accessElem(lst1, i)->value);
        i++;
        k++;
    }
    while (j < n - mid)
    {
        assignVal(temp, k, accessElem(lst2, j)->value);
        j++;
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        assignVal(lst, i, accessElem(temp, i)->value);
    }
    freeElem();
    return;
}

int main()
{
    clock_t start, end;
    int cpu_time_used, avg_time = 0;

    const int lstSize = 50000;

    for (int j = 0; j < 20; ++j)
    {
        createMem(250 * (2 << 20));
        funcinit();
        start = clock();
        Element *lst = createList(lstSize, lst);

        for (int i = 0; i < lstSize; i++)
        {
            assignVal(lst, i, rand() % 100000);
        }

        mergesort(lst, lstSize);
        end = clock();
        cpu_time_used = ((end - start)) / (CLOCKS_PER_SEC / 1000.0);
        avg_time += cpu_time_used;

        cout << "Current: " << cpu_time_used << "ms\n";
        freeElem();
        free(my_memory);
    }
    cout << "Averge Time: " << avg_time / 20 << "ms" << endl;
    cout << "Max Page Used: " << max_page << endl;
    return 0;
}