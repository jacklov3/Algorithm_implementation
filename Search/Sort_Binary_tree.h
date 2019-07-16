//
// Created by fish on 2019-07-15.
//

#ifndef ALGORITHM_SORT_BINARY_TREE_H
#define ALGORITHM_SORT_BINARY_TREE_H

#include <cstdlib>
#include <cstdio>

#define TRUE 1
#define FALSE 0
typedef int Status;
//定义二叉树的二叉链表结点结构定义
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*递归查找二叉排序树T中是否存在key
 * 指针f指向T的双亲，初始化为NULL
 * 若查找成功，则指针p指向该数据元素结点，并返回TRUE
 * 否则指向p指向查找路径上访问的最后一个结点并返回FALSE

 */
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p){
    if(!T){//查找不成功
        *p=f;
        return FALSE;
    } else if(key==T->data){//查找成功
        *p=T;
        return TRUE;
    } else if(key<T->data)
        return SearchBST(T->lchild,key,T,p);//在左子树继续查找
    else
        return SearchBST(T->rchild,key,T,p);//在右子树继续查找

}


//二叉排序树的插入操作
//查找二叉排序树，若不存在key则插入并返回TRUE，否则返回FALSE
Status InsertBST(BiTree *T,int key){
    BiTree p,s;
    if(!SearchBST(*T,key,nullptr,&p)){//查找不成功
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild=s->rchild= nullptr;
        if(!p)//p指向查找的最后的结点，若为nullptr
            *T=s;//插入s为新的根结点
        else if(key<p->data)
            p->lchild=s;//插入s为左孩子
        else
            p->rchild=s;//插入s为右孩子
        return TRUE;
    } else
        return FALSE;
}

//中序遍历二叉排序树
void InorderTraverse(BiTree T){
    if(T== nullptr)
        return;
    InorderTraverse(T->lchild);
    printf("%d ", T->data);
    InorderTraverse(T->rchild);
}

//删除二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点并返回TRUE，否则返回FALSE
Status Delete(BiTree *p){
    BiTree q,s;
    if((*p)->rchild== nullptr){//只需接它的左子树
        q=*p;*p=(*p)->lchild;free(q);
    } else if((*p)->lchild== nullptr)//只需重接它的右子树
    {
        q=*p;*p=(*p)->rchild;free(q);
    } else{//左右子树均不空
        q=*p;s=(*p)->lchild;
        while (s->rchild)//找到代删除结点的前驱
        {
            q=s;s=s->rchild;
        }
        (*p)->data=s->data;
        if(q!=*p)
            q->rchild=s->lchild;//重接q的右子树
        else
            q->lchild=s->lchild;//重接q的左子树
        free(s);
    }
    return TRUE;
}

Status DeleteBST(BiTree*T,int key){
    if(!*T)//不存在关键字等于key的数据元素
        return FALSE;
    else{
        if(key==(*T)->data)//找到关键字等于key的数据元素
            return Delete(T);
        else if(key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
    }
}



#endif //ALGORITHM_SORT_BINARY_TREE_H
