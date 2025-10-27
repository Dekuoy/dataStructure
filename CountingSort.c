#include <stdio.h>

void PrintArr(int a[], int n, int begin);
void CountingSort(int a[] ,int c[],int min ,int max ,int n);

//计数排序
//[0,0,1,2,3,4,4]
//[2,3,1,4,0,4,0]
int main()
{
    int a[] = {2,3,1,4,0,4,0};
    int c[7];
    PrintArr(a , 7 , 0);

    CountingSort(a , c , 0 , 4 , 7);
    printf("\n");
    PrintArr(c , 7 , 0);

    return 0;
}
//知道一个序列当中的值的范围
//建立辅助数组
void CountingSort(int a[] ,int c[],int min ,int max ,int n)
{
    int b[max - min+1];//0~max -min
    
    for(int i = 0;i<= max -min;i++)
    {
        b[i] = 0;
    }
    for(int i = 0;i< n;i++)
    {
        b[a[i] - min]++;//映射 ，统计每个关键字的出现次数
    }

    for(int i = 1;i<= max - min;i++)
    {
        b[i] = b[i] + b[i-1]; //统计不大于i的元素个数
    }

    for(int i = n-1;i>=0;i--)
    {
        int value = a[i];
        int index = value - min;
        int pos = b[index] -1;
        c[pos] = value;
        b[index] --;
    }
}

void PrintArr(int a[], int n, int begin)
{
    for (int i = begin; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}