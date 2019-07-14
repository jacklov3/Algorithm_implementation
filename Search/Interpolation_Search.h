//
// Created by fish on 2019-07-14.
//

#ifndef ALGORITHM_INTERPOLATION_SEARCH_H
#define ALGORITHM_INTERPOLATION_SEARCH_H

//插值查找，其算法思想是由于查找的表是有序的，而关键字在有序表中的大概位置是知道的，不必每次都是从中值分，而是按照关键字在查找范围内的
//比例来定义mid，所以它的代码与二分查找的区别只是在于mid位置的计算
int Interpolation_Search(int a[],int n,int key){
    int low,mid,high;
    low=0;
    high=n-1;
    while(low<=high){
        mid=low+((key-a[low])/(a[high]-a[low]))*(high-low);
        if(key<a[mid])
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

#endif //ALGORITHM_INTERPOLATION_SEARCH_H
