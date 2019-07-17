//
// Created by fish on 2019-07-16.
//

//最长公共子序列问题

#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int max(int a,int b);

//返x[0..m-1],y[0..n-1]的长度
int lcs(const char *X, const char *Y,int m,int n)
{
    int L[m+1][n+1];
    int i,j;
    //自下而上的构建L[m+1][n+1]
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                L[i][j]=0;
            else if (X[i-1]==Y[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
}

int max(int a,int b){
    return (a>b)?a:b;
}

int main(){
    char X[]="GCCCTAGCG";
    char Y[]="GCGCAATG";

    int m = strlen(X);
    int n = strlen(Y);
    printf("最长公共子序列的长度为：%d\n",lcs(X,Y,m,n));
    return 0;
}

