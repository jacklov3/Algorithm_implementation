//
// Created by fish on 2019-09-06.
//

#include <iostream>

using namespace std;

//计数排序
void Counting_Sort(int *init,int *sorted,const int n,int range){//传入初始化数组、待排序数组和数组长度和数据最大最小值的范围
    int *count=new int[range];//创建一个计数数组，等于最大值+2-最小值
    for(int i=0;i<range;i++)
        count[i]=0;//初始化为0
    //1.统计init数组中值的个数并写入count对应的值下标
    for(int i=0;i<n;i++){
        count[init[i]]++;
    }
    //2.计数相加，前一项加上后一项
    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    //3.反向填充数组sorted
    for(int i=n;i>0;i--){
        sorted[--count[init[i-1]]]=init[i-1];
    }
    //释放堆内存
    delete []count;
}

int main(){
    const int n=10;
    int a[n],sorted[n];
    srand(unsigned(time(NULL)));
    for(auto &x:a)
        x=rand()%100;
    for(auto &x:a)
        cout<<x<<' ';
    cout<<endl;
    Counting_Sort(a,sorted,n,100);
    for(auto &x:sorted)
        cout<<x<<' ';
    return 0;
}