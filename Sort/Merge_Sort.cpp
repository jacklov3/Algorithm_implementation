/**---------------------------------------------------------------------
    > File Name: Merge_Sort.cpp
    > Author: JackyLove
    > Mail: asaltedfishz@gmail.com 
    > Created Time: 三  9/ 4 15:02:40 2019
---------------------------------------------------------------------**/

#include<iostream>
using namespace std;

//-----------------迭代版------------------//

void Merge_Sort(int arr[],int n){
	int *a=arr;
	int *b= new int[n];//辅助数组
	for(int seg=1;seg<n;seg +=seg){
		for(int start = 0;start<n;start +=seg*2){
			int low=start, mid=min(start+seg,n),high=min(start+2*seg,n);//分别划分两个待归并的数组
			int k=low;
			int start1=start,end1=mid;
			int start2=mid,end2=high;
			while(start1<end1&& start2<end2){
				b[k++] = a[start1]<a[start2]?a[start1++]:a[start2++];
			}
			while(start1<end1){
				b[k++]=a[start1++];
			}
			while(start2<end2)
				b[k++]=a[start2++];
		}
		//交换a和b的指针指向
		int *temp = a;
		a=b;
		b=temp;
	}
	
	if(a!=arr){//如果a不是指向原数组则它是指向堆空间的数组，我们需要释放堆内存。
		for(int i=0;i<n;i++){
			b[i]=a[i];//将堆内存的数据赋予栈内存
		}
		b=a;//令b指针指向堆内存空间
	}
	delete[] b;//释放堆内存
}



//----------------递归版--------------------//




int main(){
	int a[10];
	srand(unsigned(time(NULL)));//随机种子发生器
	for(auto &x:a)
		x=rand()%100;
	for(auto &x:a)
		cout<<x<<' ';
	int len=sizeof(a)/sizeof(int);
	Merge_Sort(a,len);
	cout<<endl;
	for(auto &x:a)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
