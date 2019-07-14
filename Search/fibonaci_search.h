//
// Created by fish on 2019-07-14.
//

#ifndef ALGORITHM_FIBONACI_SEARCH_H
#define ALGORITHM_FIBONACI_SEARCH_H

//斐波那契查找，又称为黄金分隔查找(前一个数除以后一个数无限接近黄金分割数），是一种二分查找的改进算法。

int fibonaci(int *F,int n){
    int f=0;
    int g=1;
    int i=2;
    F[0]=f,F[1]=g;
    while(i<n){
        g=g+f;
        f=g-f;
        F[i]=g;
        i++;
    }
    return 0;
}


int fibonaci_search(const int *F,int *a,int n,int key){
    int low,mid,high,i,k;
    low=0;
    high=n-1;
    k=0;
    while (n>F[k]-1)//计算n位于斐波那契的位置
        k++;
    for(i=n;i<F[k]-1;i++)//将不满的数值补全
        a[i]=a[high];

    while (low<=high){
        mid=low+F[k-1]-1;//计算分割下标
        if(key<a[mid]){//关键字小于当前分割记录
            high=mid-1;
            k=k-1;//在左侧长范围内
        }
        else if(key>a[mid])
        {
            low=mid+1;
            k=k-2;//在右侧短范围内
        } else{
            if(mid<=n-1)
                return mid;//若相等，则说明mid为查找的位置
            else
                return n-1;//否则是补全数组
        }
    }
    return -1;
}

#endif //ALGORITHM_FIBONACI_SEARCH_H
