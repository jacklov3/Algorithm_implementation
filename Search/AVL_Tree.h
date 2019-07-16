//
// Created by fish on 2019-07-15.
//

#ifndef ALGORITHM_AVL_TREE_H
#define ALGORITHM_AVL_TREE_H

//定义平衡二叉树的结构
typedef struct BiTNode
{
    int data;//结点数据
    int bf;//结点的平衡因子
    struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;

//以p为根结点的右旋操作
//处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点

void R_Rotate(BiTree *p){
    BiTree L;
    L=(*p)->lchild;//L指向p的左子根结点
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    *p=L;//p指向新的根结点
}

//同理
void L_Rotate(BiTree *p){
    BiTree R;
    R=(*p)->rchild;//R指向P的右子树
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    *p=R;
}

//左平衡旋转处理
#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高

//对以指针T所指结点为根的二叉树做左平衡旋转处理
void LeftBalance(BiTree *T){
    BiTree L,Lr;
    L=(*T)->lchild;//L指向T的左子树根结点
    switch (L->bf){
        //检查T的左子树的平衡度，并做相应平衡处理
        case LH://新结点插入在T的左孩子的左子树上，要做单右旋处理
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH://新结点插入在T的左孩子的右子树上，要做双旋处理
            Lr=L->rchild;//Lr
            switch (Lr->bf){ //修改T及其左孩子的平衡因子
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:(*T)->bf=L->bf=EH;
                    break;
                case RH:(*T)->bf=EH;
                    break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);//对T的左子树作左旋平衡处理
            R_Rotate(T);//对T做右旋平衡处理
    }
}


#endif //ALGORITHM_AVL_TREE_H
