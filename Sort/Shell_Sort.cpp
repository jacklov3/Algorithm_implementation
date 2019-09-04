/**---------------------------------------------------------------------
    > File Name: Shell_Sort.cpp
    > Author: JackyLove
    > Mail: asaltedfishz@gmail.com 
    > Created Time: 三  9/ 4 12:36:59 2019
---------------------------------------------------------------------**/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Shell_Sort(int a[],int n){
	for(int gap=n>>1;gap>0;gap >>=1){
		for(int i=gap;i<n;i++){
			int current=a[i];
			int preindex = i-gap;
			while(preindex>=0&&current<a[preindex]){
				a[preindex+gap]=a[preindex];
				preindex -=gap;
			}
			a[preindex+gap]=current;
		}
		
	}
}

int main(){
	int a[10];
	srand(unsigned(time(NULL)));
	for (auto &x:a)
		x=rand()%100;
	for(auto &x:a)
		cout<<x<<' ';
	cout<<endl;
	Shell_Sort(a,10);
	for(auto &x:a)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}

		
