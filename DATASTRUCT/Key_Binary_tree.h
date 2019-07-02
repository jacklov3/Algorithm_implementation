//
// Created by fish on 2019-07-01.
//

#ifndef ALGORITHM_KEY_BINARY_TREE_H
#define ALGORITHM_KEY_BINARY_TREE_H

#include "Tree.h"

//线索二叉树的实现
typedef enum {Link,Thread} PointerTag; //Link==0表示指向左右孩子指针，Thread==1表示指向前驱或后继的线索

typedef struct BiThrNode{
    TElemType data;//
    struct BiThrNode *lchild,*rchild;//左右孩子指针
    PointerTag LTag;//左右标志
    PointerTag RTag;
}BiThrNode,*BiThrTree;

BiThrThee pre;//指向刚刚访问过的结点
//中序遍历
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);//递归左子树线索化
        if(!p->lchild)//没有左孩子
        {
            p->LTag=Thread;
            p->lchild=pre;//指向前驱
        }
        if(!pre->rchild)//前驱没有右孩子
        {
            pre->RTag=Thread;//后继线索
            pre->rchild=p;//前缀右孩子指针指向后继
        }
        pre=p;
        InThreading(p->rchild);//递归右子树线索化

    }
}

#endif //ALGORITHM_KEY_BINARY_TREE_H
