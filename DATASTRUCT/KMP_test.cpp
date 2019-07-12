//
// Created by fish on 2019-07-10.
//

#include "KMP.h"
#include <iostream>


int main(){
    const string s="BBC ABCDAB ABCDABCDABDE";
//    int index = Index(s,"world",2);
    int index = Index_KMP(s,"ABCDAB",2);
    std::cout<<index<<std::endl;


}