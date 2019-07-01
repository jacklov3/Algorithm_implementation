//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_STACK_LINKLIST_H
#define ALGORITHM_STACK_LINKLIST_H

#include <cstdlib>

#define MAXSIZE 20

typedef int SElemType;//别名
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;//别名

typedef struct LinkStack{
    LinkStackPtr top;
    int count;
}LinkStack;

//入栈
Status Push(LinkStack *L,SElemType e){
    //链栈不存在栈满的情况
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data=e;
    p->next=L->top;
    L->top=p;
    L->count++;
    return OK;
}

//出栈
Status Pop(LinkStack *L,SElemType *e){
    LinkStackPtr p;
    //栈空
    if(L->top==NULL)
        return ERROR;
    *e=L->top->data;
    p=L->top;
    L->top=L->top->next;
    free(p);
    L->count--;
    return OK;
}

#endif //ALGORITHM_STACK_LINKLIST_H
