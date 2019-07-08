//
// Created by fish on 2019-07-08.
//

#include <iostream>
using namespace std;

//递归版斐波那契数列，速度贼满好吧。算100需要几个世纪
int Fib(int n){
    return 2>n?n:Fib(n-1)+Fib(n-2);
}

//改进的高效斐波那契数列，动态规划法，由自顶向下递归，为自底向上迭代,轻松算出100的斐波那契数列
long Fib2(int n){
    long f=0 ,g=1;//fib(0),fib(1)
    while(0<n--){
        g=g+f;//生成后一项
        f=g-f;//生成前一项
    }
    return g;
}

int main(){
    cout<<Fib2(100)<<endl;
}
