#include <stdio.h>

void InsertSort1(int a[], int n);
void InsertSort2(int a[], int n);

void PrintArr(int a[],int n,int begin);
int a[7] = {38,49,65,97,76,13,27};
int b[8] = {0,38,49,65,97,76,13,27};


int main(){
    PrintArr(a,7,0);
    printf("\n");

    PrintArr(b,8,1);

    printf("\n");
    InsertSort1(a,7);
    InsertSort2(b,7);

    PrintArr(a,7,0);
    printf("\n");

    PrintArr(b,8,1);

    return 0;
}

void InsertSort1(int a[], int n){
    for(int i = 1;i < n;i++){
        //从下标一号的位置开始往前插入
        if(a[i-1] > a[i]){
            int temp = a[i];
            int j = i-1;
            while (a[j]>temp&&j>=0){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
            
            
        }
        
        
    }
}
void InsertSort2(int a[], int n){
    for(int i = 2;i <=n;i++){
        //第一个位置是哨兵
        //从下标一号的位置开始往前插入
        if(a[i-1] > a[i]){
            a[0] = a[i];
            printf("a[0]是%d\n",a[0]);
            int j = i-1;
            while (a[j]>a[0]){
                printf("%d和哨兵进行比较\n",a[j]);
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = a[0];
            
            
        }
        
        
    }
}
void PrintArr(int a[],int n ,int begin){
    for(int i = begin;i<n;i++){
        printf("%d ",a[i]);
    }
}
