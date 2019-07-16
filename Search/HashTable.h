//
// Created by fish on 2019-07-16.
//

#ifndef ALGORITHM_HASHTABLE_H
#define ALGORITHM_HASHTABLE_H

#include <cstdlib>

#define SUCCESS 1
#define UNSUCCESS 0

#define HASHSIZE 12
#define NULLKEY -32768
#define OK 1
typedef int Status;

//定义hash表结构体
typedef struct {
    int *elem;//数据元素存储基址，动态分配数组
    int count;//当前数据元素个数
}HashTable;

int m=0;//hash表表长，全局变量

//初始化hash表
Status InitHashTable(HashTable *H){
    int i;
    m=HASHSIZE;
    H->count=m;
    H->elem=(int *)malloc(m* sizeof(int));
    for(i=0;i<m;i++)
        H->elem[i]=NULLKEY;
    return OK;
}

//散列函数
int Hash(int key){
    return key%m;//除留余数法
}

//插入关键字进散列表
void InsertHash(HashTable *H,int key){
    int addr=Hash(key);//求得散列地址
    while (H->elem[addr]!=NULLKEY)//如果不为空，则冲突了
        addr=(addr+1)%m;//采用开放定址的线性探测,也可采用其它解决冲突的方法
    H->elem[addr]=key;
}

//hash表查找关键字
Status SearchHash(HashTable H,int key,int *addr){
    *addr=Hash(key);//求散列地址
    while (H.elem[*addr]!=key){//如果不为空，则冲突
        *addr=(*addr+1)%m;//开放地址的线性探测
        if(H.elem[*addr]==NULLKEY || *addr==Hash(key)){
            //如果循环回到原点，说明关键字不存在
            return UNSUCCESS;
        }
    }
    return SUCCESS;
}





#endif //ALGORITHM_HASHTABLE_H
