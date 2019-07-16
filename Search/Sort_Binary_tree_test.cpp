//
// Created by fish on 2019-07-15.
//

#include "Sort_Binary_tree.h"

int main(){
    int a[]={62,88,58,47,35,73,51,99,37,93};
    int n= sizeof(a)/sizeof(int);
    BiTree T= nullptr;
    for(int i=0;i<n;i++){
        InsertBST(&T,a[i]);
    }
    InorderTraverse(T);
    InsertBST(&T,56);
    printf("\n");
    InorderTraverse(T);
    DeleteBST(&T,56);
    printf("\n");
    InorderTraverse(T);
    return 0;

}