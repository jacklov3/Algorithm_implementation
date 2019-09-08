//
// Created by fish on 2019-06-29.
//

#ifndef ALGORITHM_LINEAR_ARRAY_H
#define ALGORITHM_LINEAR_ARRAY_H


#define MAXSIZE 20 //线性表能存储的最大容量
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0//状态宏
typedef int Status;//状态
typedef int ElemType;//类型别名
typedef struct {
    ElemType data[MAXSIZE];/*数组存储数据元素，最大值为MAXSIZE*/
    int length; /*线性表当前长度*/
}SqList;//定义这个结构体别名

/*获取元素Getitem,获取线性表中第i个元素，并赋值给e(传入指针，才能把数据传出来)
 */
Status GetItem(SqList L,int i,ElemType *e){
    //如果i不在L的长度中，或者L没有元素
    if(L.length==0||i<1 || i>L.length)
        return ERROR;
    *e = L.data[i-1];//i存储在i-1的下标中
    return OK;
}

//插入元素，要在原表操作，所以要传入表指针
Status ListInsert(SqList *L,int i,ElemType e){
    //依旧判断i的位置
    if(i<1||i>L->length+1)
        return ERROR;
    //表满了
    if(L->length==MAXSIZE)
        return ERROR;
    //不是在尾部插入，需要后移动数据,因为第i个元素存放在列表的第i-1个位置，所以需要减1
    for(int j=L->length-1;j>=i-1;j--)
        L->data[j+1]=L->data[j];
    L->data[i-1]=e;//插入值
    L->length++;//线性表长度加1
    return OK;
}

//删除第i个元素
Status Listdelete(SqList *L,int i,ElemType *e){
    if(L->length==0)
        return ERROR;
    //判断i的位置
    if(i<1||i>L->length)
        return ERROR;
    //非删除尾元素,
    if(i<L->length)
    {
        *e=L->data[i-1];//保存删除的元素
        //元素前移
        for(int j = i-1;j<L->length-1;j++)
            L->data[j]=L->data[j+1];

    } else{
        *e=L->data[i-1];
    }
    L->length--;
    return OK;
}



#endif //ALGORITHM_LINEAR_ARRAY_H
