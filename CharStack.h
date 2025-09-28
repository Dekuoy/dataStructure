#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stackNode
{
    char data;
    struct stackNode *next;
    
}StackNode;

typedef struct{
    StackNode *top;
} CharStack;


bool initCharStack(CharStack *cs){
    if(cs == NULL) return false;
    cs->top = NULL;
    return true;
}

bool stackEmpty(CharStack *cs){
    return cs->top==NULL;
}

bool pushChar(CharStack *cs,char x){
    if(cs==NULL) return false;

    StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
    if(newNode==NULL) return false;//分配失败
    newNode->data = x;
    cs->top=newNode;
    newNode->next = NULL;

    printf("已入栈:%c\n",x);
    return true;
}

bool popChar(CharStack *cs,char*x){
    if(cs==NULL||cs->top==NULL) return false;
    
    StackNode *temp = cs->top;
    *x = temp->data;
    cs->top = cs->top->next;
    free(temp);

    printf("已出栈：%c\n",*x);
    return true;
}

bool getTop(CharStack *cs,char *x){
    if(cs==NULL||cs->top==NULL) return false;

    *x = cs->top->data;
    printf("栈顶是:%c\n",*x);
    return true;
}

void destroyStack(CharStack *cs){
    char x;
    while (!stackEmpty(cs))
    {
        popChar(cs,&x);
    }
    
}


