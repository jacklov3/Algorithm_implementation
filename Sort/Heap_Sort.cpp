//
// Created by fish on 2019-09-05.
//


#include <iostream>
using namespace std;

//调整成大顶堆
void Max_heapify(int a[],int start,int end){
    int dad=start;//一颗二叉树的父节点
    int son=2*start+1;//子结点
    while(son<=end){
        if(son+1<=end&&a[son]<a[son+1])
            son++;
        if(a[dad]>a[son])
            return;
        else{//父结点再与孙子结点比较
            std::swap(a[dad],a[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}

void Heap_sort(int a[],int n){
    //建立初始堆，从n/2-1第一个非叶子结点开始
    for(int i=n/2-1;i>=0;i--)
        Max_heapify(a,i,n-1);
    for(int i=n-1;i>0;i--){
        std::swap(a[i],a[0]);
        Max_heapify(a,0,i-1);
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
    Heap_sort(a,len);
    cout<<endl;
    for(auto &x:a)
        cout<<x<<' ';
    cout<<endl;
    return 0;
}
