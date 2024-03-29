//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_STACK_ARRAY_H
#define ALGORITHM_STACK_ARRAY_H
#define MAXSIZE 20

#include "Binary_Tree.h"


typedef int SElemType;//别名
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct {
    SElemType data[MAXSIZE];
    int top;//用于指出栈顶位置
}SqStack;//结构体别名

//初始化栈
Status InitStack(SqStack **S){
    *S=(SqStack*)malloc(sizeof(SqStack));
    if(!(*S)) exit(OVERFLOW);
    (*S)->top=-1;
    return OK;
}



//进栈
Status Push(SqStack *S,SElemType e){
    if(S->top==MAXSIZE-1)//栈满
        return ERROR;
    S->top++;
    S->data[S->top]=e;
    return OK;
}

//出栈
Status Pop(SqStack *S,SElemType *e){
    if(S->top==-1)//栈空
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}

#endif //ALGORITHM_STACK_ARRAY_H
