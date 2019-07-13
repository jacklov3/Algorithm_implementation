//
// Created by fish on 2019-07-12.
//

#ifndef ALGORITHM_HUFFMAN_H
#define ALGORITHM_HUFFMAN_H

//定义哈夫曼树的存储结构，

#include <cstdlib>
#include <math.h>
#include <cstring>

typedef struct {
    unsigned int weight;//权值
    unsigned int parent,lchild,rchild;//父节点和孩子结点:-1是根结点的序号
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;//用来存储每个叶子结点的哈夫曼编码


void select_minium(HuffmanTree HT,int k,int &min1,int &min2);
int min(HuffmanTree HT,int k);
//构造哈夫曼树,wet存放n个权值
HuffmanTree create_HuffmanTree(int *wet,int n){
    //一颗又n个孩子结点的哈夫曼树有2*n-1个结点
    int total=2*n-1;
    HuffmanTree HT=(HuffmanTree)malloc(total* sizeof(HTNode));
    if(!HT) exit(OVERFLOW);
    int i;
    //HT[0],HT[1]..HT[n-1]中存放需要编码的n个叶子结点
    for(i=0;i<n;i++){
        HT[i].parent=-1;
        HT[i].lchild=-1;
        HT[i].rchild=-1;
        HT[i].weight=*wet;
        wet++;
    }

    //HT[n],HT[n+1]...HT[2n-2]中存放的是中间构造的每棵二叉树的根结点
    for(;i<total;i++){
        HT[i].parent=-1;
        HT[i].parent=-1;
        HT[i].rchild=-1;
        HT[i].weight=0;
    }
    int min1,min2;//用来存储每一轮选出的两个权值最小且parent为0的节点
    //每一轮比较后选择出min2和min2构成一颗二叉树，最后构成一颗哈夫曼树
    for(i=n;i<total;i++){
        select_minium(HT,i,min1,min2);
        HT[min1].parent=i;
        HT[min2].parent=i;
        HT[i].lchild=min1;
        HT[i].rchild=min2;
        HT[i].weight=HT[min1].weight+HT[min2].weight;
    }
    return HT;
}

//从HT数组的前k个元素中选出权最小且parent为-1的两个，分别将其序号保存在min1和min2中
void select_minium(HuffmanTree HT,int k,int &min1,int &min2){
    min1=min(HT,k);
    min2=min(HT,k);
}
//从HT数组的前k个元素中选出权最小且parent为-1的元素，并将该元素的序号返回
int min(HuffmanTree HT,int k){
    int i=0;
    int min;
    int min_weight;
    while(HT[i].parent!=-1)
        i++;
    min_weight=HT[i].weight;
    min=i;
    //选出权最小且parent为-1的元素，将其序号赋给min
    for(;i<k;i++){
        if(HT[i].weight<min_weight&&HT[i].parent==-1){
            min_weight=HT[i].weight;
            min=i;
        }
    }
    //选出weight最小的元素后，将其parent置1，使得下一次比较时将其排除在外。
    HT[min].parent=1;
    return min;
}


//哈夫曼编码，两种方式，1.从根结点到叶子结点比遍历  2.从叶子结点到根结点的遍历

//1.从根到叶子结点无栈非递归遍历
void HuffmanCoding1(HuffmanTree HT,HuffmanCode &HC,int n){
    //用来保存指向每个哈夫曼编码串的指针
    HC=(HuffmanCode)malloc(n* sizeof(char*));
    if(!HC)exit(OVERFLOW);
    //临时空间
    char *code=(char*)malloc(n*sizeof(char));
    if(!code)exit(OVERFLOW);
    int cur=2*n-2;////当前遍历的结点序号
    int code_len=0;//定义编码长度
    //构建好赫夫曼树后，把weight用来当做遍历树时每个节点的状态标志
    //weight=0表明当前节点的左右孩子都还没有被遍历
    //weight=1表示当前节点的左孩子已经被遍历过，右孩子尚未被遍历
    int i;
    for(i=0;i<cur+1;i++){
        HT[i].weight=0;
    }
    //从根节点开始遍历，最好回到根结点结束
    //当cur为根结点的parent时，退出循环
    while (cur!=-1) {
        //先遍历左孩子
        if (HT[cur].weight == 0) {
            HT[cur].weight = 1;
            if (HT[cur].lchild != -1) {//如果当前结点不是叶子结点，则记下编码，并继续向左遍历
                code[code_len++] = '0';
                cur = HT[cur].lchild;
            } else {
                code[code_len] = '\0';
                HC[cur] = (char *) malloc((code_len + 1) * sizeof(char));
                if (!HC[cur])exit(OVERFLOW);
                strcpy(HC[cur], code);//复制编码串

            }
        }
            //遍历右孩子
        else if (HT[cur].weight == 1) {
            HT[cur].weight = 2;//表明左右孩子均被遍历过了
            if (HT[cur].rchild != -1) {
                code[code_len++] = '1';
                cur = HT[cur].rchild;
            }
        }
            //退回父结点
        else {
            HT[cur].weight = 0;
            cur = HT[cur].parent;
            --code_len;
        }

    }
    free(code);

}



//2.从叶子结点到根结点逆向遍历求每个字符的赫夫曼编码，并保存在HC中
void HuffmanCoding2(HuffmanTree HT,HuffmanCode &HC,int n){
    //用来保存指向每个哈夫曼编码串的指针
    HC=(HuffmanCode)malloc(n* sizeof(char*));
    if(!HC) exit(OVERFLOW);
    //临时空间，用于保存每次求的哈夫曼编码
    //对于有n个叶子结点的哈夫曼树，各叶子结点的编码长度最长不超过n-1
    //加一个'\0'结束符号，因此分配的数组长度最长为n即可
    char *code=(char*)malloc(n* sizeof(char));
    if(!code)exit(OVERFLOW);
    code[n-1]='\0';//编码结束符
    int i;
    for(i=0;i<n;i++){
        int current=i;//定义当前访问的结点
        int father=HT[i].parent;//当前结点的父结点
        int start =n-1;//每次编码的位置，初始化为编码结束符的位置
        while(father!=-1){
            if(HT[father].lchild==current)//如果是左孩子，则编码为0
                code[--start]='0';
            else    //如果是右孩子，则编码为1
                code[--start]='1';
            current=father;
            father=HT[father].parent;
        }
        //为第i个字符的编码串分配存储空间
        HC[i]=(char*)malloc((n-start)* sizeof(char));
        if(!HC[i]) exit(OVERFLOW);
        strcpy(HC[i],&code[start]);
    }
    free(code);//释放临时堆空间

}



#endif //ALGORITHM_HUFFMAN_H
