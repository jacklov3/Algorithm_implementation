//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_STACK_SHAREARRAY_H
#define ALGORITHM_STACK_SHAREARRAY_H

#define MAXSIZE 20//最大容量
typedef int SElemType;//别名
#define OK 1
#define ERROR 0
typedef int Status;

//两个栈共享栈空间
typedef struct {
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

//入栈
Status Push(SqDoubleStack *S,SElemType e,int stackNumber){
    if(S->top1+1==S->top2)//栈满
        return ERROR;
    if(stackNumber==1)
        S->data[++S->top1]=e;
    else if(stackNumber==2)
        S->data[--S->top2]=e;
    return OK;
}

//出栈
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber){
    if(stackNumber==1){
        if(S->top1==-1)
            return ERROR;//栈空
        else
            *e=S->data[S->top1--];//将栈顶元素赋予e
    } else if(stackNumber==2){
        if(S->top2==MAXSIZE)
            return ERROR;
        else
            *e=S->data[S->top2++];//
    }
    return OK;
}

#endif //ALGORITHM_STACK_SHAREARRAY_H
