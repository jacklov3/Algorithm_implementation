//
// Created by fish on 2019-07-14.
//

#include <iostream>
#include "fibonaci_search.h"

int main(){

    int f[10];
    fibonaci(f,10);
//    for(auto &x:f)
//        std::cout<<x<<std::endl;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int n= sizeof(a)/ sizeof(int);
    std::cout<<n<<std::endl;
    std::cout<<fibonaci_search(f,a,10,5)<<std::endl;
    return 0;
}