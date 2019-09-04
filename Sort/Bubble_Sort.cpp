//
// Created by fish on 2019-09-02.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void bubble_sort(int [],int);

int main(){
    int a[10];
    srand((unsigned)time(NULL));
    for (auto &x:a)
        x=rand()%100;
    for(auto &x:a)
        cout<<x<<' ';
    int n=sizeof(a)/sizeof(int);
    bubble_sort(a,n);
    cout<<endl;
    for (auto &x:a)
        cout<<x<<' ';

	return 0;

}

//冒泡排序算法
void bubble_sort(int a[],int n){
    bool changed = true;
    for(int i=n-1;i>0&&changed==true;i--){
        changed=false;
        for(int j=0;j<i;j++){
            if (a[j]>a[j+1]){
				int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                changed=true;
            }
        }

    }

}
