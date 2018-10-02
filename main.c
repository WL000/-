/*邻接表存储无向图*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode
{
    int adjvex;               //指向顶点的弧
    struct ArcNode *nextarc;   //指向下一条弧的指针
} ArcNode;

typedef struct VNode
{
    char data;             //顶点信息
    ArcNode *firstarc;    //指向第一条依附该顶点的弧的指针
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;   //无向图顶点数和弧数
} ALGraph;

int Find(ALGraph G,char v)
{
    /*寻找两个定点在矩阵中的位置*/
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data==v)
            return i;
    }
}

void Print_LJB(ALGraph G)
{
    /*打印邻接表*/
    int i;
    ArcNode *p;
    printf("\n该无向图的邻接表为：\n");
    for(i=0; i<G.vexnum; i++)
    {
        printf("%d",i);
        p=G.vertices[i].firstarc;
        while(p!=NULL)
        {
            printf("-->%d",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
}


void Creat_T(ALGraph G)
{
    /*创建邻接表*/
    int i,m,n,n1,TD;
    char v0,v1,v2;
    ArcNode *p,*q,*r;
    printf("请输入无向图的顶点数:\n");
    scanf("%d",&G.vexnum);
    printf("请输入无向图的边数:\n");
    scanf("%d",&G.arcnum);
    printf("请输入顶点信息：\n");

    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;   //初始化该指针
    }
    printf("请输入边：\n");
    for(i=0; i<G.arcnum; i++)
    {
        fflush(stdin);
        scanf("%c%c",&v1,&v2);
        m=Find(G,v1);
        n=Find(G,v2);
        p=(ArcNode *)malloc(sizeof(ArcNode));
        p->nextarc=NULL;
        p->adjvex=m;
        p->nextarc=G.vertices[n].firstarc;
        G.vertices[n].firstarc=p;

        q=(ArcNode *)malloc(sizeof(ArcNode));
        q->nextarc=NULL;
        q->adjvex=n;
        q->nextarc=G.vertices[m].firstarc;
        G.vertices[m].firstarc=q;
    }
    Print_LJB(G);  //打印邻接表
    printf("请输入指定的结点：\n");
    fflush(stdin);
    scanf("%c",&v0);
    n1=Find(G,v0);
    r=G.vertices[n1].firstarc;
    while(r!=NULL)     //计算指定顶点的度
    {
        TD++;
        r=r->nextarc;
    }
    printf("%c的度为%d",v0,TD);

}
int main()
{
    /*测试函数*/
    ALGraph  G;
    Creat_T(G);
}
