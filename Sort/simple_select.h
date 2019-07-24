//
// Created by fish on 2019-07-24.
//

#ifndef ALGORITHM_SIMPLE_SELECT_H
#define ALGORITHM_SIMPLE_SELECT_H
//简单选择排序

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void select_sort(int *a,int n){
    for(int i=0;i<n-1;i++){
        int min=i;//记录最小值的下标
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
            swap(&a[i],&a[min]);
        }
    }
}

#endif //ALGORITHM_SIMPLE_SELECT_H
