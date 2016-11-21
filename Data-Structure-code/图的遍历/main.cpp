/**********************************
ͼ��BFS��DFS
Author:��ͤ���� Date:2014-02-20
Email:zyb_maodun@163.com
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include "data_structure.h"

int main()
{
	Graph Gp = create_graph();

	//������ȱ���
	printf("��ͼ����������ȱ�����\n");
	printf("�Ӷ���A����DFS�Ľ����");
	DFS_traverse(Gp,0);
	printf("\n");
	printf("�Ӷ���H����DFS�Ľ����");
	DFS_traverse(Gp,7);
	printf("\n");
	printf("�Ӷ���E����DFS�Ľ����");
	DFS_traverse(Gp,4);
	printf("\n");
	printf("\n");

	//������ȱ���
	printf("��ͼ���й�����ȱ�����\n");
	printf("�Ӷ���A����BFS�Ľ����");
	BFS_traverse(Gp,0);
	printf("\n");
	printf("�Ӷ���H����BFS�Ľ����");
	BFS_traverse(Gp,7);
	printf("\n");
	printf("�Ӷ���E����BFS�Ľ����");
	BFS_traverse(Gp,4);
	printf("\n");

	int i;
	//�ͷŵ�Ϊÿ����������������ڴ�
	for(i=0;i<NUM;i++)
	{
		free(Gp[i].first);
		Gp[i].first = 0;  //��ֹ����ָ��Ĳ���
	}

	//�ͷŵ�Ϊ����������������ڴ�
	free(Gp);
	Gp = 0;
	return 0;
}
