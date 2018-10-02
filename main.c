/*�ڽӱ�洢����ͼ*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode
{
    int adjvex;               //ָ�򶥵�Ļ�
    struct ArcNode *nextarc;   //ָ����һ������ָ��
} ArcNode;

typedef struct VNode
{
    char data;             //������Ϣ
    ArcNode *firstarc;    //ָ���һ�������ö���Ļ���ָ��
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;   //����ͼ�������ͻ���
} ALGraph;

int Find(ALGraph G,char v)
{
    /*Ѱ�����������ھ����е�λ��*/
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vertices[i].data==v)
            return i;
    }
}

void Print_LJB(ALGraph G)
{
    /*��ӡ�ڽӱ�*/
    int i;
    ArcNode *p;
    printf("\n������ͼ���ڽӱ�Ϊ��\n");
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
    /*�����ڽӱ�*/
    int i,m,n,n1,TD;
    char v0,v1,v2;
    ArcNode *p,*q,*r;
    printf("����������ͼ�Ķ�����:\n");
    scanf("%d",&G.vexnum);
    printf("����������ͼ�ı���:\n");
    scanf("%d",&G.arcnum);
    printf("�����붥����Ϣ��\n");

    for(i=0; i<G.vexnum; i++)
    {
        fflush(stdin);
        scanf("%c",&G.vertices[i].data);
        G.vertices[i].firstarc=NULL;   //��ʼ����ָ��
    }
    printf("������ߣ�\n");
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
    Print_LJB(G);  //��ӡ�ڽӱ�
    printf("������ָ���Ľ�㣺\n");
    fflush(stdin);
    scanf("%c",&v0);
    n1=Find(G,v0);
    r=G.vertices[n1].firstarc;
    while(r!=NULL)     //����ָ������Ķ�
    {
        TD++;
        r=r->nextarc;
    }
    printf("%c�Ķ�Ϊ%d",v0,TD);

}
int main()
{
    /*���Ժ���*/
    ALGraph  G;
    Creat_T(G);
}
