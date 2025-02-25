//单链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* typedef struct lNode{
    int e;
    struct lNode* next;
}lNode , *LinkList; */

typedef struct lNode{
    int e;
    struct lNode* next;
};
typedef struct lNode *LinkList;

//无头结点的初始化
void initLinkList1(LinkList l){
    l = NULL;
}

//有头结点的初始化
bool initLinkList2(LinkList *l){
    *l = (struct lNode*)malloc(sizeof(struct lNode));
    if(*l ==NULL){
        return false;//内存不足,无法分配空间
    }
    (*l)->next = NULL;
    return true;
}


