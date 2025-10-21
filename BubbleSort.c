#include <stdio.h>

void BubbleSort(int a[], int n);

void PrintArr(int a[], int n, int begin);
int a[7] = {38, 49, 65, 97, 76, 13, 27};

int main()
{
    PrintArr(a, 7, 0);
    printf("\n");
    BubbleSort(a, 7);
    PrintArr(a, 7, 0);

    return 0;
}

void BubbleSort(int a[], int n)
{
    int temp,flag;
    
    for (int i = 0; i < n; i++)
    {   
        flag = 0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            return;
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
