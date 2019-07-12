//
// Created by fish on 2019-07-10.
//

#include "Binary_Tree.h"

int main(){
    BiTree T;
    CreateBiTree(&T);
//    PreOrderTraverse(T);
//    InOrderTraverse(T);
    InOrder_Traverse(T);

    return 0;

}