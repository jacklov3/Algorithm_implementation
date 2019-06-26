#include <iostream>
using namespace std;


//冒泡排序 事件复杂度：O(n^2)
void BubbleSort(int a[],int len){
    //排序躺数
    for(int i = 0; i<len-1;i++){
        //每躺排序
        for(int j=0;j<len-1-i;j++){
            if (a[j]>a[j+1]){
                int tmp = a[j];
                a[j]=a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

//改进的冒泡排序 事件复杂度:O(n^2)
void AdvanceBubbleSort(int a[],int len){
    //设置标志位，若为false则表示无交换，即排序好了，否则继续循环

    for(int i = 0;i<len-1;i++){
        bool changed = false;
        for(int j=0;j<len-1-i;j++){
            if (a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                changed = true;
            }
            if (!changed)
                break;
        }
    }
}


//选择排序 事件复杂度: O(n^2)
void SelectSort(int a[],int len){
    for(int i=0;i<len;i++){
        //初始化无序列中最小的值
        int index=i;
        for(int j=i+1;j<len;j++){
            if (a[j]<a[index]){
                index=j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i]=temp;
    }
}

//插入排序 复杂度：O(n^2)
void InsertSort(int a[],int len){
    //记录已经排序的下标
   int preIndex,current;
   for(int i=1;i<len;i++){
       preIndex = i-1;
       current = a[i];
       while (preIndex>=0&&a[preIndex]>current){
           a[preIndex+1]=a[preIndex];
           preIndex--;
       }
       a[preIndex+1] = current;
   }
}

//希尔排序，选择步长不断为n/2，最后步长为1时即插入排序 复杂度：O（nlogn)
void ShellSort(int a[],int len){
    int j;
    for(int gap = len>>1;gap>0;gap>>=1)
        for(int i = gap;i<len;i++){
            int temp = a[i];
            for(j=i-gap;j>=0&&a[j]>temp;j-=gap)
                a[j+gap]=a[j];
            a[j+gap]=temp;
        }
}



int main() {
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int b[]={1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(a)/ sizeof(int);
    //BubbleSort(a,len);
//    AdvanceBubbleSort(a,len);
//    SelectSort(a,len);
//    InsertSort(a,len);
    ShellSort(a,len);
    for (auto x:a){
        cout<<x<<' ';
    }
    return 0;

}

