//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_QUEUE_ARRAY_H
#define ALGORITHM_QUEUE_ARRAY_H

namespace QueueArray{
#define MAXSIZE 20

typedef int QElemType;//别名
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct {
    QElemType *data;//数组指针
    int front;//队头指针
    int rear;//队尾指针
}SqQueue;

//循环队列初始化
Status InitQueue(SqQueue *Q){
    Q->data=(QElemType *)malloc(MAXSIZE* sizeof(QElemType));//数组名字
    if(!Q->data)exit(OVERFLOW);
    Q->front=Q->rear=0;//都是指向第一个数组元素的指针
    return OK;
}

//返回队列长度
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//入队列
Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%MAXSIZE == Q->front)//队列满的判断
        return ERROR;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}

//出队列
Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front==Q->rear)//队空的情况
        return ERROR;
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}


}






#endif //ALGORITHM_QUEUE_ARRAY_H
