//
// Created by fish on 2019-06-28.
//
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;
const int BUCKET_NUM=10;

//链表
struct ListNode{
    explicit ListNode(int i=0):mData(i),mNext(nullptr){}
    ListNode* mNext;
    int mData;
};

//链表插入
ListNode* insert(ListNode* head,int val){
    ListNode dummyNode;
    ListNode *newNode = new ListNode(val);
    ListNode *pre,*curr;
    dummyNode.mNext =head;
    pre=&dummyNode;
    curr=head;
    while (curr!= nullptr && curr->mData<=val){
        pre=curr;
        curr=curr->mNext;
    }
    newNode->mNext = curr;
    pre->mNext=newNode;
    return dummyNode.mNext;
}

ListNode* Merge(ListNode *head1,ListNode *head2){
    ListNode dummyNode;
    ListNode *dummy = &dummyNode;
    while (head1!=nullptr&&head2!= nullptr){
        if(head1->mData <=head2->mData){
            dummy->mNext = head1;
            head1 = head1->mNext;
        } else{
            dummy->mNext = head2;
            head2 = head2->mNext;
        }
        dummy = dummy->mNext;
    }
    if(head1!= nullptr) dummy->mNext=head1;
    if(head2!=nullptr) dummy->mNext = head2;
    return dummyNode.mNext;
}

void BucketSort(int n,int arr[]) {
    vector<ListNode *> buckets(BUCKET_NUM, (ListNode *) (0));
    for (int i = 0; i < n; ++i) {
        int index = arr[i] / BUCKET_NUM;
        ListNode *head = buckets.at(index);
        buckets.at(index) = insert(head, arr[i]);
    }
    ListNode *head = buckets.at(0);
    for (int i = 1; i < BUCKET_NUM; ++i)
        head = Merge(head, buckets.at(i));

}