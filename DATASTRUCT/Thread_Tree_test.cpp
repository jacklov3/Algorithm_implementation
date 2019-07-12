//
// Created by fish on 2019-07-11.
//

#include "Thread_Binary_tree.h"

int main(){
    BiThrTree P,T= nullptr;
    CreateBiThrTree(&T);
    InOrderThreading(&P,T);//线索化
    InOrderTraverse(P);//中序遍历
    return 0;
}

