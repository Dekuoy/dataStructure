#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 10

//静态分配线性表
typedef struct 
{
    
    int data[MaxSize];//用静态的数组存放数据
    int length;
    
} SqList;

//初始化一个线性表
void initSqList(SqList *list){
    //将list中的每一个元素初始为0
    for (int i = 0; i < MaxSize; i++)
    {
        list->data[i] = 0;
    }
    //设置list初始当前长度为0
    list->length = 0;
}

//在线性表的第i个位置插入元素e
bool insertList(SqList *list , int i , int e){
    //对i进行合法性判断
    if(i<1||i>list->length+1||list->length >= MaxSize){
        return false;
    }


    //将第i个位置及其之后的元素往后移一个位置
    for (int j = list->length; j >=i; j--)
    {
        list->data[j] = list->data[j-1];
    }
    
    //插入元素e
    list->data[i -1] = e;
    //增加list长度
    list->length++;
    return true;
}

//删除操作，删除表中第i个位置的元素，并返回
bool deleteList(SqList *list , int i , int * e){
    //对i进行合法性判断
    if(i<1||i>list->length+1){
        return false;
    }
    e = list->data[i -1];
    for (int j = list->length-1; j > i-1; j--)
    {
        list->data[j-1] = list->data[j]; 
    }
    list->length--;
    return true;

    
}

//查找第i个位置的元素,按位查找
bool getElem(SqList *list , int i , int *e){
     //对i进行合法性判断
    if(i<1||i>list->length+1){
        return false;
    }
    e = list->data[i-1];
    return true;
}

//按值查找，查找元素的位置
bool getLocation(SqList *list , int *e , int *i){
    //遍历数组是否有对应的值，有则返回true和给出对应的索引
    for (int j = 0; j < list->length; j++)
    {
        
        if(list->data[j] == *e){
            *i = j;
            return true;
        }
    }
    return false;
    

}


int main(){
    SqList list;
    initSqList(&list);
}


