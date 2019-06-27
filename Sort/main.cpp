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

//归并排序 迭代版
//返回两数的中较小的数
int min(int x,int y){
    return x<y?x:y;
}

//归并排序
void MergeSort(int arr[],int len){
    int *a=arr;
    int *b =(int*)malloc(len* sizeof(int));
    int seg,start;
    for(seg = 1;seg<len;seg+=seg) {
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    //排序完成，将b指针指向a数组，并释放b数组
    if (a!=arr){
        int i;
        for(i=0;i<len;i++)
            b[i]=a[i];
        b=a;
    }
    free(b);

}

//归并排序，递归版
void MergeSort2(int arr[],int reg[],int start,int end){
    if(start>=end)
        return;
    int len = end-start,mid=(len>>1)+start;
    int start1 = start,end1=mid;
    int start2=mid+1,end2=end;
    MergeSort2(arr,reg,start1,end1);
    MergeSort2(arr,reg,start2,end2);
    int k = start;
    while (start1<=end1 && start2<=end2)
        reg[k++] = arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
    while(start1<=end1)
        reg[k++]=arr[start1++];
    while(start2<=end2)
        reg[k++]=arr[start2++];
    for(k=start;k<=end;k++)
        arr[k]=reg[k];
}

void merge_sort(int arr[],const int len){
    int reg[len];
    MergeSort2(arr,reg,0,len-1);
}

//快速排序算法 递归法
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}

void QuickSort(int a[],int start,int end){
    if(start>=end)
        return;
    int base = a[end];
    int left = start,right = end-1;
    while(left<right){
        //从左到右找到第一个比base大的数
        while(a[left]<base&&left<right)
            left++;
        while (a[right]>=base&&left<right)//从右向左找到第一个比base小的数
            right--;
        swap(&a[left],&a[right]);//交换两者
    }
    //若找到左侧有比base大的序列，交换base与left
    if(a[left]>=a[end])
        swap(&a[left],&a[end]);
    else
        left++;
    if(left)
        QuickSort(a,start,left-1);
    QuickSort(a,left+1,end);
}

void quick_sort(int a[],int len){
    QuickSort(a,0,len-1);
}



int main() {
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int b[]={1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(a)/ sizeof(int);
    //BubbleSort(a,len);
//    AdvanceBubbleSort(a,len);
//    SelectSort(a,len);
//    InsertSort(a,len);
//    ShellSort(a,len);
//    MergeSort(a,len);
//    merge_sort(a,len);
    quick_sort(a,len);
    for (auto x:a){
        cout<<x<<' ';
    }
    return 0;

}

