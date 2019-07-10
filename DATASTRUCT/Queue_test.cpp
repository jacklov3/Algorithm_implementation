//
// Created by fish on 2019-07-10.
//

#include "Queue_LinkList.h"
#include "Queue_Array.h"
#include <iostream>
using namespace std;
typedef QueueArray::SqQueue SqQueue;

//测试链表队列
void QueueLink(LinkQueue *Q){
    InitQueue(Q);//初始化队列
    for(int i=0;i<10;i++)//入队列
        EnQueue(Q,i);
    for(int i=0;i<10;i++)
    {
        QElemType result;
        DeQueue(Q,&result);
        cout<<result<<endl;
    }
//    DestoryQueue(Q);
}

//测试数组队列
void Queue_Array(SqQueue *Q){
    QueueArray::InitQueue(Q);
    for(int i=1;i<10;i++)
        QueueArray::EnQueue(Q,i);
    for(int i=0;i<10;i++) {
        int e;
        QueueArray::DeQueue(Q, &e);
        cout<<e<<endl;
    }
}

int main(){
//    LinkQueue Q;
//    QueueLink(&Q);
    SqQueue Q;
    Queue_Array(&Q);
}