//单链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lNode{
    int e;
    struct lNode* next;
};

typedef struct lNode lNode ,*LinkList;

/* typedef struct lNode{
    int e;
    struct lNode* next;
}lNode , *LinkList;
 */


//无头结点的初始化
void initLinkList1(LinkList l){
    l = NULL;
}

//有头结点的初始化
bool initLinkList2(LinkList *l){
    *l = (lNode*)malloc(sizeof(lNode));
    if(*l ==NULL){
        return false;//内存不足,无法分配空间
    }
    (*l)->next = NULL;
    return true;
}


//插入节点
bool insertList(LinkList l , int i ,int e){
   lNode* p;//指针p指向当前扫描到的节点
    p = l;
    int j = 0;
    while (p !=NULL && j < i-1)
    {
        p = p->next;
        j++;
    }


    return insertNextNode(p ,e);
}


//向前插入节点
bool insertPriorNode(lNode* p , int e){
    if (p == NULL) {
        return false;
    }
    lNode* s = (lNode*)malloc(sizeof(lNode));
    if (s == NULL) {
        return false;
    }
    s->e = p->e;
    s->next = p->next;
    p->next = s;
    p->e = e;
    return true;
}

//向后插入节点
bool insertNextNode(lNode *p , int e){
    if(p == NULL){
        return false;
    }
    lNode* s = (lNode*)malloc(sizeof(lNode));
    if(s == NULL){
        return false;
    }
    s->next = p->next;
    s->e = e;
    p->next = s;
    return true;
}

//删除节点
bool deleteNode(LinkList l , int i , int * e){//删除表l中第i个位置的元素，并用e返回删除元素的值
    //对i进行判断
    if(i < 1){
        return false;
    }
    int j = 0;
    lNode * p ;
    p = l;
    while (p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }

    if(p == NULL || p->next == NULL){
        return false;
    }//将p指向被删除节点的前一个节点

    lNode* q;
    q = p->next;//将q指向被删除的节点
    *e = q->e;
    p->next = q->next;
    free(q);
    return true;
}

