//
// Created by fish on 2019-07-16.
//
#include <iostream>
#include "HashTable.h"

int main(){
    HashTable T;
    InitHashTable(&T);
    int a[]={12,67,56,16,25,37,22,29,15,47,48,34};
    int n=sizeof(a)/ sizeof(int);
    for(int i=0;i<n;i++){
        InsertHash(&T,a[i]);
    }
    int result;
    if(SearchHash(T,12,&result))
        std::cout<<result<<std::endl;
    else
        std::cout<<"查找失败"<<std::endl;
    return 0;
}
