//
// Created by fish on 2019-07-12.
//
#include <printf.h>
#include "Huffman.h"

int main(){
    printf("请输入需要编码的字符个数：");
    int n;
    scanf("%d",&n);
    int wet[n];
    printf("请输入%d个字符的权值：",n);
    for(int i=0;i<n;i++){
        scanf("%d",&wet[i]);
    }
    HuffmanTree  HT=create_HuffmanTree(wet,n);
    HuffmanCode HC;
    HuffmanCoding1(HT,HC,n);
    for(int i=0;i<n;i++){
        printf("%s\n",HC[i]);
    }
    return 0;
}
