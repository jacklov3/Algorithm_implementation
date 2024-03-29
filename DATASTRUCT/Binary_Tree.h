//
// Created by fish on 2019-07-01.
//

#ifndef ALGORITHM_BINARY_TREE_H
#define ALGORITHM_BINARY_TREE_H

#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;


typedef int Status;//状态
#define ERROR 0
#define OK 1
typedef char TElemType;
typedef struct TNode{//结点
    TElemType data;//数据
    struct TNode * lchild,*rchild;//左右孩子结点
}TNode,*BiTree;

//前序遍历
void PreOrderTraverse(BiTree T){
    if(T== nullptr)
        return;
    printf("%c",T->data);//先遍历根结点
    PreOrderTraverse(T->lchild);//再递归遍历左子树
    PreOrderTraverse(T->rchild);//再递归遍历右子树
}

//非递归中序遍历
Status InOrder_Traverse(BiTree T){
    stack<BiTree> s;
    BiTree p=T;
    while(p||!s.empty()){//栈不空
        if(p){s.push(p);p=p->lchild;}//向左走到尽头
        else{
            p= s.top();
            cout<<p->data<<endl;
            s.pop();
            p=p->rchild;
        }
    }
    return OK;
}


//中序遍历
void InOrderTraverse(BiTree T){
    if(T== nullptr)
        return;
    InOrderTraverse(T->lchild);//中序遍历左子树
    printf("%c",T->data);//打印结点
    InOrderTraverse(T->rchild);//再递归遍历右子树
}

//后序遍历
void PostOrderTraverse(BiTree T){
    if(T== nullptr)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c",T->data);
}

//按前序输入二叉树中结点的值
//#表示空树，构造二叉链表表示二叉树T。
Status CreateBiTree(BiTree *T){
        char data;
        scanf("%c",&data);
        if (data == '#')
            *T = nullptr;
        else {
            *T = (BiTree) malloc(sizeof(TNode));
            if (!*T) exit(OVERFLOW);
            (*T)->data = data;//生成根结点
            CreateBiTree(&(*T)->lchild);//构造左子树
            CreateBiTree(&(*T)->rchild);//构造右子树
        }
    return OK;
}



#endif //ALGORITHM_BINARY_TREE_H
