//
// Created by fish on 2019-07-01.
//

#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#define MAX_TREE_SIZE 100
typedef int TElemType;

typedef struct CTNode{//孩子节点
    int child;
    struct CTNode *next;
}*ChildPtr;
typedef struct {//表头结点
    TElemType data;
    ChildPtr firstchild;
}CTBox;
typedef struct {//树结构
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;//根的位置和结点数
}CTree;


#endif //ALGORITHM_TREE_H
