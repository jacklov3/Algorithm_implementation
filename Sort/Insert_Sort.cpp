/**---------------------------------------------------------------------
    > File Name: Insert_Sort.cpp
    > Author: JackyLove
    > Mail: asaltedfishz@gmail.com 
    > Created Time: 三  9/ 4 10:22:43 2019
---------------------------------------------------------------------**/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Insert_Sort(int a[],int n){
	for(int i=1;i<n;i++){
		int current = a[i];//当前值
		int preindex=i-1; //已排序的数组的下标
		while(current<a[preindex]&&preindex>=0){
			a[preindex+1]=a[preindex];
			preindex--;
		}
		a[preindex+1]=current;
	}
}

int main(){
	srand(unsigned(time(NULL)));
	int a[10];
	for (auto &x:a)
		x=rand()%100;
	for(auto &x:a)
		cout<<x<<' ';
	cout<<endl;
	int n = sizeof(a)/sizeof(int);
	cout<<n<<endl;
	Insert_Sort(a,n);
	for(auto &x:a)
		cout<<x<<' ';
	cout<<endl;
	return 0;

}
