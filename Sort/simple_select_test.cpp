//
// Created by fish on 2019-07-24.
//

#include "simple_select.h"
#include <iostream>
using namespace std;

int main(){
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(a)/ sizeof(int);
    select_sort(a,n);
    for(auto i:a)
        cout<<i<<' ';
    return 0;
}