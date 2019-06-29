//
// Created by fish on 2019-06-29.
//

#ifndef ALGORITHM_LINEAR_LINKLIST_H
#define ALGORITHM_LINEAR_LINKLIST_H

#include <cstdlib>
#include <ctime>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;


//定义链表节点
struct Node {
    ElemType data;//数据域
    struct Node *next;//指针域

};
typedef struct Node *LinkList;//定义Node结构体指针的别名

//获取第i个元素
Status GetElem(LinkList L,int i,ElemType *e){//注意该L是一个指针类型,他就是头节点
    LinkList p;//声明一个节点p
    p = L->next;//令p指向第一个有元素的节点
    int j=1;//计数器
    while(p && j<i){//p不为空或者计数器j还没有等于i时
        p=p->next;//指向下一个节点
        ++j;//计数器加1
    }
    //如果p指针为空，则表示没有元素，
    if (!p||j>i)//第i个元素不存在
        return ERROR;
    *e=p->data;//取第i个元素的数据
    return OK;
}

//在单链表的第i个位置插入元素，假设有头节点(方便操作)
Status ListInsert(LinkList *L,int i,ElemType e){//这里的L是头指针，即指向头节点的指针
    LinkList p,s;//节点指针类型
    p = *L;//头节点
    int j=1;//计数器
    while(p&&j<i){//寻找第i个节点
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;//第i个元素不存在

    s = (LinkList)malloc(sizeof(Node));//动态申请堆内存
    s->data=e;
    s->next = p->next;
    p->next=s;
    return OK;

}

//删除链表中第i个元素

Status ListDelete(LinkList *L,int i,ElemType *e){
    LinkList p,q;//声明节点指针
    p = *L;//头节点
    int j=1;//计数器
    while (p->next && j<i){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)
        return ERROR;
    q=p->next;
    p->next=q->next;//将q的后继复值给p的后继
    *e=q->data;
    free(q);
    return OK;
}

//创建链表，头插入法,随机生成n个元素
void CreateListHead(LinkList *L,int n){//L是头指针
    LinkList p;//声明i 一个节点
    srand(time(0));//初始化随机化种子
    *L = (LinkList)malloc(sizeof(Node));//建立头节点
    (*L)->next=NULL;//建立一个带头节点的单链表
    for(int i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));//生成新节点
        p->data=rand()%100+1;//随机生成100以内的数字
        p->next=(*L)->next;
        (*L)->next=p;//插入到表头
    }
}

//创建链表,尾插入法，随机生成n个元素
void CreateListTail(LinkList *L,int n){//L是头指针
    LinkList r,p;
    (*L)=(LinkList)malloc(sizeof(Node));//新建立节点
    srand(time(0));
    r=*L;//指向头节点
    for(int i=0;i<n;i++){
        p = (LinkList)malloc(sizeof(Node));//声明节点指针
        p->data=rand()%100+1;//随机生成100以内的数字
        r->next=p;//将表尾终端接待您的指针指向新节点
        r=p;//将当前的新节点定义为表尾终端结点
    }
    r->next=NULL;
}

//删除整个链表
Status ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->next;//p指向第一个节点
    while(p){
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;

}



#endif //ALGORITHM_LINEAR_LINKLIST_H
