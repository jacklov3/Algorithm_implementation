/**---------------------------------------------------------------------
    > File Name: Select_Sort.cpp
    > Author: JackyLove
    > Mail: asaltedfishz@gmail.com 
    > Created Time: 二  9/ 3 12:12:42 2019
---------------------------------------------------------------------**/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;


void Select_Sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if (a[j]<a[min])
				min=j;
		}
		//将这一趟最小的数交换到第i个位置
		if (min!=i){
		int temp = a[min];
		a[min]=a[i];
		a[i]=temp;
		}
	}
}

int main(){
	int a[10];
	srand(unsigned(time(NULL)));
	for(auto &x:a){
		x=rand()%100;
	}
	for(auto &x:a){
	cout<<x<<' ';
	}
	cout<<endl;
	Select_Sort(a,10);
	for(auto &x:a){
	cout<<x<<' ';
	}
	return 0;

}

