//
// Created by fish on 2019-09-05.
//

#include <iostream>
using namespace std;


//----------递归版--------------//
void Quick_Sort(int a[],int start,int end){//传入数组和长度
    if(start>=end)
        return;//递归返回条件
    int key=a[start];//取数组第一个值为比较标准
    int i=start;
    int j=end;
    while(i!=j){
        while(a[j]>=key&&j>i)j--;
        a[i]=a[j];
        while(a[i]<=key&&i<j)i++;
        a[j]=a[i];
    }
    a[i]=key;
    Quick_Sort(a,0,i-1);
    Quick_Sort(a,i+1,end);
}




//--------------迭代版------------本质依旧是分治法
struct Range{
    int low,high;
    Range(int l=0,int h=0){
        low=l;
        high=h;
    }
};

void Quick_Sort_recur(int a[],const int n){
    if (n<=0)
        return;
    Range r[n];
    int p=0;
    r[p++]=Range(0,n-1);
    while(p){
        Range range = r[--p];//取第一对区间结构体
        if(range.low>=range.high)
            continue;
        int key = a[range.low];
        int i=range.low,j=range.high;
        while(i!=j){
            while(a[j]>=key&&j>i)j--;
            a[i]=a[j];
            while(a[i]<=key&&i<j)i++;
            a[j]=a[i];
        }
        a[i]=key;
        r[p++]=Range(range.low,i-1);
        r[p++]=Range(i+1,range.high);
    }
}



int main(){
    int a[10];
    srand(unsigned(time(NULL)));//随机种子发生器
    for(auto &x:a)
        x=rand()%100;
    for(auto &x:a)
        cout<<x<<' ';
    int len=sizeof(a)/sizeof(int);
//    Quick_Sort(a,0,len-1);
    Quick_Sort_recur(a,len);
    cout<<endl;
    for(auto &x:a)
        cout<<x<<' ';
    cout<<endl;
    return 0;
}
