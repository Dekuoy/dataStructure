#include <stdio.h>


void PrintArr(int a[], int n, int begin);
void Swap(int a[], int i, int j);

void BuildMaxHeap(int a[] ,int len);

void HeapSort(int a[], int len);



int a[] = {0,38, 49, 65, 97, 76, 13, 27};

int main()
{
    PrintArr(a, 8, 1);
    printf("\n");
    HeapSort(a, 8);
    PrintArr(a, 8, 1);

    return 0;
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

//完全二叉树中，当 i>= 1&& i<= n/2时，i为分支节点。
//堆排序所使用的数组从下标1开始存数据
//步骤：将数组整理成大根堆或小根堆的形式
    //  进行一轮选择排序
    //  排序后的序列已经确定了一个元素的最终位置
void BuildMaxHeap(int a[] ,int len){
    for(int i = len/2;i>0;i--)//从最大的一个分支节点往前整理
    {
        int k = i;
        a[0] = a[k];
        for(int j = k*2;j<=len;j = j*2)//j指向分支节点的左孩子
        {
            if(a[j] < a[j+1]&& j < len){//如果右兄弟值更大，j就指向右兄弟
                j++;
            }
            if(a[0] >= a[j])
            {
                break;
            }
            else
            {
                a[k] = a[j];
                k = j;                  //将i指向j所在的位置，在循环中继续往下比较是否符合大根堆的特性
            }
        }
        a[k] = a[0];                    //循环结束，分支节点找到了合适的位置
    }
}

void HeapSort(int a[], int len)
{
    BuildMaxHeap(a , len);

    for(int i = len-1 ; i>0;i--)
    {
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        BuildMaxHeap(a, i-1);
    }
}
