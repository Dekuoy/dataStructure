#define MaxSize 10
typedef struct stack
{
    int data[MaxSize];
    int top;            //栈顶指针
}SqStack;//顺序栈

void testStack(){
    SqStack s;
}

void initStack(SqStack *s){
    s->top = -1;
}

int ifNull(SqStack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

