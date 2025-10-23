#include <stdio.h>

void ChooseSort(int a[], int n);

void PrintArr(int a[], int n, int begin);
void Swap(int a[], int i, int j);


int a[7] = {38, 49, 65, 97, 76, 13, 27};

int main()
{
    PrintArr(a, 7, 0);
    printf("\n");
    ChooseSort(a, 7);
    PrintArr(a, 7, 0);

    return 0;
}

void ChooseSort(int a[], int n)
{
    int minIndex;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void PrintArr(int a[], int n, int begin)
{
    for (int i = begin; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void Swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}