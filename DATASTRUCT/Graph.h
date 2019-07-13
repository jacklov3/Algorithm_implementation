//
// Created by fish on 2019-07-12.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H

#include <cstdio>
#include <cstdlib>
#include "Queue_Array.h"

typedef char VertexType; //顶点类型
typedef int EdgeType;//边上的权值
#define MAXVEX 100 //最大顶点数
#define INFINITY 65535//无穷

//邻接矩阵表示
typedef struct {
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
    int numVertexes,numEdges;//顶点数和边数
}MGraph;
void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for(i=0;i<G->numVertexes;i++)//建立顶点表
        scanf(&G->vexs[i]);
    for(i=0;i<G->numVertexes;i++)
        for(j=0;i<G->numVertexes;j++)
            G->arc[i][j]=INFINITY;//邻接矩阵初始化

    for(k=0;k<G->numEdges;k++){
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);//输入边和权
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];//因为是无向图，矩阵对称
    }
}


//邻接表表示

//边表的结点结构体
typedef struct EdgeNode{//边表结点
    int adjvex;//邻接点域，存储该结点对应的下标
    EdgeType weight;//用于存储权值，对于非网图可以不需要
    struct EdgeNode *next;//链接下一个邻接点
}EdgeNode;

//顶点的结构体
typedef struct VertexNode{//顶点表结点
    VertexType data;
    EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[MAXVEX];

//图的结构题
typedef struct {
    AdjList adjList;
    int numVertexes,numEdges;//图中当前顶点数和边数
}GraphAdjList;


//建立图的邻接表结构
void CreateALGraph(GraphAdjList *G){
    printf("输入顶点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);//输入顶点数和边数
    for(int i=0;i<G->numVertexes;i++)
    {
        scanf(&G->adjList[i].data);//输入顶点信息
        G->adjList[i].firstedge= nullptr;//将边表置为空
    }
    for(int k=0;k<G->numEdges;k++){//建立边表
        int i,j;
        printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d,%d",&i,&j);//输入边(vi,vj)上的顶点序号
        //邻接阵
        EdgeNode *e=(EdgeNode*)malloc(sizeof(EdgeNode));//申请空间
        e->adjvex=j; //邻接序号为j
        e->next=G->adjList[i].firstedge;//将e指针指向当前顶点指向的结点
        G->adjList[i].firstedge=e;//将当前顶点的指针指向e

        //逆邻接阵
        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex=i;//邻接序号为i
        e->next=G->adjList[j].firstedge;//将e指针指向当前顶点指向的结点
        G->adjList[j].firstedge=e;//将当前顶点的指针指向e
    }
}


//图的遍历
#define MAX 100
#define TRUE 0
#define FALSE 1
//深度优先搜索：类似于树的先根遍历，其实就是一个递归的过程，邻接矩阵版存储结点
typedef int Boolean;//布尔类型
Boolean visited[MAX];//访问标志的数组

//邻接矩阵的深度优先递归算法
void  DFS(MGraph G,int i)
{
    int j;
    visited[i]=TRUE;
    printf("%c",G.vexs[i]);//打印顶点
    for(j=0;j<G.numVertexes;j++)
        if(G.arc[i][j]==1&&!visited[j])
            DFS(G,j);//对未访问的邻接顶点递归调用
}

void DFSTraverse(MGraph G){
    int i;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=FALSE;//初始化所有结点都是未访问过的状态
    for(i=0;i<G.numVertexes;i++)
        if(!visited[i])
            DFS(G,i);//对未调用过的结点调用DFS
}

//邻接表的深度优先递归算法
void DFS(GraphAdjList GL,int i){
    EdgeNode *p;
    visited[i]=TRUE;
    printf("%c",GL.adjList[i].data);//打印顶点
    p=GL.adjList[i].firstedge;
    while (p){
        if(!visited[p->adjvex])
            DFS(GL,p->adjvex);
        p=p->next;
    }
}

void DFSTraberse(GraphAdjList GL){
    for(int i=0;i<GL.numVertexes;i++){
        visited[i]=FALSE;
    }
    for(int i=0;i<GL.numVertexes;i++){
        if(!visited[i])
            DFS(GL,i);
    }
}


//邻接矩阵的广度遍历算法，类似于树的层次遍历，需要用到队列
void BFSTraverse(MGraph G){
    int i,j;
    QueueArray::SqQueue Q;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=FALSE;//初始化访问数组
    QueueArray::InitQueue(&Q);//初始化队列
    for(i=0;i<G.numVertexes;i++){//对每一个顶点做循环
        if(!visited[i])//若是没有访问过
        {
            visited[i]=TRUE;
            printf("%c",G.vexs[i]);//打印顶点
            QueueArray::EnQueue(&Q,i);//入队列
            while(!QueueArray::QueueEmpty(Q));//
            {
                DeQueue(&Q,&i);//将队中元素出队列
                for(j=0;j<G.numVertexes;j++){
                    //判断其它顶点若与当前顶点存在边且未访问过
                    if(G.arc[i][j]==1&&!visited[j])
                    {
                        visited[j]=TRUE;
                        printf("%c",G.vexs[j]);//打印顶点
                        QueueArray::EnQueue(&Q,j);//将找到的此顶点入队列
                    }

                }
            }

        }

    }

}

//邻接表的广度遍历算法
void BFSTraverse(GraphAdjList *GL){
    int i;
    EdgeNode *p;
    QueueArray::SqQueue Q;
    for(i=0;i<GL->numVertexes;i++){
        visited[i]=FALSE;//初始化
    }
    QueueArray::InitQueue(&Q);
    for(i=0;i<GL->numVertexes;i++)
    {
        if(!visited[i]){
            visited[i]=TRUE;
            printf("%c",GL->adjList[i].data);//打印顶点
            QueueArray::EnQueue(&Q,i);
            while (!QueueArray::QueueEmpty(Q)){
                QueueArray::DeQueue(&Q,&i);
                p=GL->adjList[i].firstedge;//找到当前顶点边表链表头指针
                while (p){
                    if(!visited[p->adjvex]){
                        visited[p->adjvex]=TRUE;
                        printf("%c",GL->adjList[p->adjvex].data);
                        QueueArray::EnQueue(&Q,p->adjvex);//将此顶点入队列
                    }
                    p=p->next;//指针指向下一个邻接点
                }
            }
        }
    }
}

#endif //ALGORITHM_GRAPH_H
