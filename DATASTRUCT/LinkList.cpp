//
// Created by fish on 2019-09-06.
//
#include <iostream>
#include "Linear_LinkList.h"
using namespace std;

int main(){
    LinkList head= nullptr;//链表的头指针
//    CreateListHead(&head,10);
    head=Create(10);

    PrintList(head);
    cout<<endl;
    if(ListInsert(head,1,100)){
        PrintList(head);
    }
}

