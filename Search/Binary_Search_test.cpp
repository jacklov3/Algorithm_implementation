//
// Created by fish on 2019-07-14.
//

#include "Binary_Search.h"
#include <iostream>

int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n= sizeof(a)/ sizeof(int);
    int z=Binary_Search(a,n,5);
    std::cout<<z<<std::endl;
}