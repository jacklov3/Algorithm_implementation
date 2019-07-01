//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_KMP_H
#define ALGORITHM_KMP_H

#include <string>
using namespace std;

//普通匹配,返回T子串在主串S中的第pos个字符之后的位置
int Index(string S,string T,int pos){
    int i=pos;
    int j=1;
    while (i<=S[0] && j<=T[0]){//索引0位置存储的是串的长度
        if(S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}


//kmp模式匹配

//返回子串T的next数组
void get_next(string T,int *next){
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    while (i<T[0]){
        if(j==0 || T[i]==T[j]){//T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
            ++i;
            ++j;
            next[i]=j;
        } else
            j=next[j];//若字符不相同，则j值回溯
    }
}

int Index_KMP(string S,string T,int pos){
    int i=pos;
    int j=1;
    int next[255];
    get_next(T,next);
    while(i<=S[0]&&j<T=T[0]){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        } else{
            j=next[j];
        }
    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}



#endif //ALGORITHM_KMP_H
