//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_QUEUE_LINKLIST_H
#define ALGORITHM_QUEUE_LINKLIST_H

#include <cstdlib>
#include <math.h>

#define MAXSIZE 20

typedef int QElemType;//别名
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front,rear;//队头和队尾指针
}LinkQueue;

//入队
Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)
        exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}

//出队列
Status DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q->rear==Q->front)
        return ERROR;
    p=Q->front->next;//队头节点
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}



#endif //ALGORITHM_QUEUE_LINKLIST_H
