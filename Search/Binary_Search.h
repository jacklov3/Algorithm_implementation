//
// Created by fish on 2019-07-14.
//

#ifndef ALGORITHM_BINARY_SEARCH_H
#define ALGORITHM_BINARY_SEARCH_H

//二分查找，要求表是顺序表
int Binary_Search(int *a,int n,int key){
    int low,high,mid;
    low=0;
    high=n-1;
    while (low<=high){
        mid=(low+high)>>1;
        if(key<a[mid])//若比中值小
            high=mid-1;
        else if(key>a[mid])//若比中值大
            low=mid+1;
        else
            return mid;
    }
    return -1;
}


#endif //ALGORITHM_BINARY_SEARCH_H
