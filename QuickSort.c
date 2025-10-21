#include <stdio.h>

void QuickSort(int a[], int low, int high);

void PrintArr(int a[], int n, int begin);
void Swap(int a[], int i, int j);

int Pivot(int a[], int low, int high);

int a[7] = {38, 49, 65, 97, 76, 13, 27};

int main()
{
    PrintArr(a, 7, 0);
    printf("\n");
    QuickSort(a, 0, 6);
    PrintArr(a, 7, 0);

    return 0;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = Pivot2(a, low, high);
        QuickSort(a, low, pivot - 1);
        QuickSort(a, pivot + 1, high);
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
int Pivot(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;

    while (low < high)
    {
        while (a[high] >= pivot && low < high)
        {
            high--;
        } 
        while (a[low] <= pivot && low < high)
        {
            low++;
        }

        if (low < high)
        {
            Swap(a, low, high);
        }
    }
    a[i] = a[low];
    a[low] = pivot;
    return low;
}

int Pivot2(int a[], int low, int high)
{
    int pivot = a[low];


    while (low < high)
    {
        while (a[high] >= pivot && low < high)
        {
            high--;
        }
        a[low] = a[high];
        while (a[low] <= pivot && low < high)
        {
            low++;
        }
        a[high] = a[low];

        
    }
    
    a[low] = pivot;
    return low;
}