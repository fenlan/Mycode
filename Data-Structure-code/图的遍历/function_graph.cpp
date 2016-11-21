/**********************************
��װʵ��ͼ��BFS��DFS��ز���
Author:��ͤ���� Date:2014-02-20
Email:zyb_maodun@163.com
***********************************/

#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

/*
����ͼ��������Ӧ��ͼ
*/
Graph create_graph()
{
	//Ϊ���涥�������Ϣ���������ռ䣬����������ֵ
	Graph graph = (Graph)malloc(NUM*sizeof(Head));
	int i;
	//�������Ű�������˳���0�������
	for(i=0;i<NUM;i++)
		graph[i].data = 'A' + i;
	
	//Ϊÿ���ڵ��Ӧ�ĵĵ������еĽڵ����ռ�
	Node *p00 = (Node *)malloc(sizeof(Node));
	Node *p01 = (Node *)malloc(sizeof(Node));
	Node *p10 = (Node *)malloc(sizeof(Node));
	Node *p11 = (Node *)malloc(sizeof(Node));
	Node *p12 = (Node *)malloc(sizeof(Node));
	Node *p20 = (Node *)malloc(sizeof(Node));
	Node *p21 = (Node *)malloc(sizeof(Node));
	Node *p22 = (Node *)malloc(sizeof(Node));
	Node *p30 = (Node *)malloc(sizeof(Node));
	Node *p31 = (Node *)malloc(sizeof(Node));
	Node *p40 = (Node *)malloc(sizeof(Node));
	Node *p41 = (Node *)malloc(sizeof(Node));
	Node *p50 = (Node *)malloc(sizeof(Node));
	Node *p51 = (Node *)malloc(sizeof(Node));
	Node *p60 = (Node *)malloc(sizeof(Node));
	Node *p61 = (Node *)malloc(sizeof(Node));
	Node *p70 = (Node *)malloc(sizeof(Node));
	Node *p71 = (Node *)malloc(sizeof(Node));

	//Ϊ���������еĽڵ��������Ը�ֵ
	p00->vertex = 1;
	p00->pNext = p01;
	p01->vertex = 2;
	p01->pNext = NULL;
	p10->vertex = 0;
	p10->pNext = p11;
	p11->vertex = 3;
	p11->pNext = p12;
	p12->vertex = 4;
	p12->pNext = NULL;
	p20->vertex = 0;
	p20->pNext = p21;
	p21->vertex = 5;
	p21->pNext = p22;
	p22->vertex = 6;
	p22->pNext = NULL;
	p30->vertex = 1;
	p30->pNext = p31;
	p31->vertex = 7;
	p31->pNext = NULL;
	p40->vertex = 1;
	p40->pNext = p41;
	p41->vertex = 7;
	p41->pNext = NULL;
	p50->vertex = 2;
	p50->pNext = p51;
	p51->vertex = 6;
	p51->pNext = NULL;
	p60->vertex = 2;
	p60->pNext = p61;
	p61->vertex = 5;
	p61->pNext = NULL;
	p70->vertex = 3;
	p70->pNext = p71;
	p71->vertex = 4;
	p71->pNext = NULL;

	//��������ÿ����������������
	graph[0].first = p00;	
	graph[1].first = p10;
	graph[2].first = p20;	
	graph[3].first = p30;
	graph[4].first = p40;	
	graph[5].first = p50;
	graph[6].first = p60;	
	graph[7].first = p70;

	return graph;
}

/*
����ͼGp��pos���㣨���Ϊpos�Ķ��㣩�ĵ�һ���ڽӶ������ţ���������ڣ��򷵻�-1
*/
int first_vertex(Graph Gp,int pos)
{
	if(Gp[pos].first)  //��������ڽӶ��㣬���ص�һ���ڽӶ�������
		return 	Gp[pos].first->vertex;
	else              //��������ڣ��򷵻�-1
		return -1;
}

/*
cur������pos���㣨cur��pos��Ϊ�������ţ�������һ���ڽӶ��㣬
����ͼGp�У�pos����ģ������cur���㣩��һ���ڽӶ�������,��������ڣ��򷵻�-1
*/
int next_vertex(Graph Gp,int pos,int cur)
{
	Node *p = Gp[pos].first; //p��ʼָ�򶥵�ĵ�һ���ڽӵ�
	//ѭ��pos�ڵ��Ӧ������ֱ��pָ�����Ϊcur���ڽӵ�
	while(p->vertex != cur)
		p = p->pNext;

	//������һ���ڵ�����
	if(p->pNext)
		return p->pNext->vertex; 
	else 
		return -1;
}

bool visited[NUM];   //����ȫ�ֱ����������飬��������ÿ���ڵ�ķ�����Ϣ

/*
�����Ϊbegin�Ķ���������ݹ�������ȱ�����ͨͼGp
*/
void DFS(Graph Gp, int begin)
{
	//����������Ϊbegin�Ķ���������򣬲����������Ϣ
	printf("%c ",Gp[begin].data);
	visited[begin] = true; 

	//ѭ�����ʵ�ǰ�ڵ�������ڽӵ㣨���ýڵ��Ӧ������
	int i;
	for(i=first_vertex(Gp,begin); i>=0; i=next_vertex(Gp,begin,i))
	{
		if(!visited[i])  //������δ�������ڽӽڵ㣬�ݹ����DFS
			DFS(Gp,i);
	}
} 

/*
�����Ϊbegin�Ľڵ㿪ʼ������ȱ���ͼGp��Gp��������ͨͼҲ�����Ƿ���ͨͼ
*/
void DFS_traverse(Graph Gp,int begin)
{
	int i;
	for(i=0;i<NUM;i++)    //��ʼ��������־����
		visited[i] = false; 

	//�ȴ����Ϊbegin�Ķ��㿪ʼ������Ӧ����ͨͼ
	DFS(Gp,begin);
	//����Ƿ���ͨͼ����ѭ����֤ÿ��������ͨ��ͼ�еĶ��㶼�ܱ�������   
	for(i=0;i<NUM;i++)
	{	    
		if(!visited[i])
			DFS(Gp,i);
	}
}

/*
�����Ϊbegin�Ķ��㿪ʼ��������ȱ���ͼGp��Gp��������ͨͼҲ�����Ƿ���ͨͼ
*/
void BFS_traverse(Graph Gp,int begin)
{
	int i;
	for(i=0;i<NUM;i++)    //��ʼ��������־����
		visited[i] = false;

	//�ȴ����Ϊbegin�Ķ��㿪ʼ������Ӧ����ͨͼ
	BFS(Gp,begin);
	//����Ƿ���ͨͼ����ѭ����֤ÿ��������ͨ��ͼ�еĶ��㶼�ܱ�������   
	for(i=0;i<NUM;i++)
	{	if(!visited[i])
			BFS(Gp,i);		
	}
}

/*
�����Ϊbegin�Ķ��㿪ʼ��������ȱ�����ͨͼGp
*/
void BFS(Graph Gp,int begin)
{
	//����������Ϊbegin�Ķ���������򣬲����������Ϣ
	printf("%c ",Gp[begin].data);
	visited[begin] = true; 

	int i;
	int pVertex;  //��������Ӷ����г��ӵĶ�������
	PQUEUE queue = create_queue();  //����һ���յĸ�������
	en_queue(queue, begin);          //���Ƚ����Ϊbegin�Ķ������
	while(!is_empty(queue))
	{
		de_queue(queue,&pVertex);
		//ѭ��������������pVertex����������ڽӶ���,�������ʺ���ڽӶ������
		for(i=first_vertex(Gp,pVertex); i>=0; i=next_vertex(Gp,pVertex,i))
		{
			if(!visited[i])
			{
				printf("%c ",Gp[i].data);
				visited[i] = true;
				en_queue(queue,i);
			}
		}
	}
	//���ٶ��У��ͷ����Ӧ���ڴ�
	destroy_queue(queue);
}
