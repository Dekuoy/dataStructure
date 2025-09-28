#include "LinkStack.h"
int main(){
    struct LinkStackNode *p;
    struct LinkStackNode ln;
    ln.data =1 ;
    p = &ln;
    printf("ln的地址是%p/n",p);
    return 0;
}

void initLinkStack(LinkStack *ls){
    *ls = NULL;
}

int Empty(LinkStack *ls){
    if(*ls == NULL){
        return 1;
    }else{return 0;}
}

bool initHeadNodeLinkStack(LinkStack *ls){
    *ls = malloc(sizeof(struct LinkStackNode));
    if(*ls == NULL){
        return false;
    }
    (*ls)->next = NULL;
    return true;
}