#include <stdio.h>

void ShellSort(int a[], int n);

void PrintArr(int a[],int n,int begin);
int a[7] = {38,49,65,97,76,13,27};


int main(){
    PrintArr(a,7,0);
    printf("\n");
    ShellSort(a,7);
    PrintArr(a,7,0);

    return 0;
}

void ShellSort(int a[], int n){
   int d,i,j,temp;
   for(d = n /2;d>= 1;d = d/2){//分块
        for(i = d+ 1;i<n;i++){//插入排序
            if(a[i-d]>a[i]){
                temp = a[i];
                j=i-d;
                while(a[j]>temp&& j>=0){
                    a[j+d] = a[j];
                    j = j-d;
                }
                a[j+d] = temp;
            }
        }           
   }
}

void PrintArr(int a[],int n ,int begin){
    for(int i = begin;i<n;i++){
        printf("%d ",a[i]);
    }
}
