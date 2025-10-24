#include <stdio.h>
#include <stdlib.h>


void PrintArr(int a[], int n, int begin);
void Swap(int a[], int i, int j);


void MergeSort(int a[], int low ,int high);

void Merge(int a[] ,int low ,int mid,int high);


int a[] = {38, 49, 65, 97, 76, 13, 27};
int *b;

int main()
{
    int n = sizeof(a)/ sizeof(a[0]);
    b = (int *)malloc(n* sizeof(int));

    PrintArr(a, 7, 0);
    printf("\n");

    MergeSort(a, 0 , 6);
    free(b);
    PrintArr(a, 7, 0);

    return 0;
}



void PrintArr(int a[], int n, int begin)
{
    for (int i = begin; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}


void MergeSort(int a[], int low ,int high)
{
    if(low < high){
        int mid = (low+high)/2;     //中间点
        MergeSort(a,low ,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low ,mid ,high);
    }
}

void Merge(int a[] ,int low ,int mid,int high)
{
    int i,j,k;
    for(k = low;k<= high;k++)
    {
        b[k] = a[k];
    }
    for(i = low ,j = mid + 1, k = low;
        i<= mid &&j <= high;
        k++)
    {
        if(b[i] <= b[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = b[j];
            j++;
        }
    }
    while(i<=mid)
    {
        a[k] = b[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        a[k] = b[j];
        k++;
        j++;
    }
    
   
}
