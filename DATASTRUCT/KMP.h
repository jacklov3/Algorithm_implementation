//
// Created by fish on 2019-06-30.
//

#ifndef ALGORITHM_KMP_H
#define ALGORITHM_KMP_H

#include <string>
using namespace std;

//普通匹配,返回T子串在主串S中的第pos个字符之后的位置
int Index(const string S,const string T,int pos){
    int i=pos;
    int j=0;
    while (i<S.length() && j<T.length()){//索引0位置存储的是串的长度
        if(S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>T.length()-1)
        return i-T.length();
    else
        return 0;
}


//kmp模式匹配

//返回子串T的next数组
void get_next(const string &T,int next[]) {
    int j=0;
    int k=-1;
    next[j]=k;
    while(j<T.length()-1){//第j个元素
        if(k==-1 || T[k]==T[j]) {
            ++j;++k;
            if(T[j]!=T[k])//如果T[j]和T[k]相等的或者初始化则next[j+1]必然是k+1
                next[j]=k;
            else    //如果回退后还是和原来的字符相等，则必然又是不匹配的，继续回退，直接使用next数组即可
                next[j]=next[k];
        }

        else
            k=next[k];//不相等则递归回退，直接使用next数组即可
    }
}

int Index_KMP(const string &S,const string &T,int pos){
    int i=pos;
    int j=0;
    int next[T.length()];
    get_next(T,next);
    while(i<S.length()&&j<T.length()){
        if(j==0||S[i]==T[j]){
            ++i;
            ++j;
        } else{
            j=next[j];
        }
    }
    if(j>T.length()-1)
        return i-T.length();
    else
        return 0;
}
#endif //ALGORITHM_KMP_H
