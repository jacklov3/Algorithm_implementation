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

//初始化队列
Status InitQueue(LinkQueue *Q){
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)exit(OVERFLOW);
    Q->front->next= nullptr;
    return OK;
}


//入队
Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s) exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}

//出队列
Status DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q->rear==Q->front)//若队列为空，则出错
        return ERROR;
    p=Q->front->next;//队头节点
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}


//销毁队列
Status DestoryQueue(LinkQueue *Q){
    //销毁队列Q
    while(Q->front){
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}


#endif //ALGORITHM_QUEUE_LINKLIST_H
