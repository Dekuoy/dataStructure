#include <stdlib.h>
#include <stdbool.h>

#define InitSize 10//顺序表的初始长度

//动态分配线性表

/*
malloc(unsigned int size): 申请空间, 参数是空间的大小
free(ElemType* p): 释放空间，参数为对应类型的指针
*/

typedef struct 
{
    int *data; //指示动态分配的指针
    int MaxSize;//顺序表的最大容量
    int length;//顺序表的当前长度
    
} SeqList;

void initList(SeqList *list){
    list->data = (int *)malloc(sizeof(int)*InitSize);
    list->MaxSize = InitSize;
    list->length = 0;
}

void increaseList(SeqList *list ,int len){
    int *p = list->data;
    list->data = (int*)malloc(sizeof(int)*(InitSize+len));
    for (int i = 0; i < list->length; i++)
    {
        //将元素复制到新的空间
        list->data[i] = p[i];
    }
    //修改最大容量
    list->MaxSize = list->MaxSize + len;

    //释放原来的空间
    free(p);
    
}

//查找第i个位置的元素
bool getElem(SeqList *list , int i , int *e){
     //对i进行合法性判断
    if(i<1||i>list->length+1){
        return false;
    }
    e = list->data[i-1];
    return true;
}