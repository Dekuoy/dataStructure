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
bool insertLink(LinkList l , int i ,int e){
   lNode* p;//指针p指向当前扫描到的节点
    p = l;
    int j = 0;
    while (p !=NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL){
        return false;
    }
    lNode *s = (lNode*)malloc(sizeof(lNode*));
    s->e = e;
    s->next = p->next;
    p->next = s;
    
    return true;
}


