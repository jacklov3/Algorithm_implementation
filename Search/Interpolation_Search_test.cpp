//
// Created by fish on 2019-07-14.
//

//查找查找

#include "Interpolation_Search.h"
#include <iostream>

int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(a)/ sizeof(int);
    int result = Interpolation_Search(a,n,11);
    std::cout<<result<<std::endl;
    return 0;
}