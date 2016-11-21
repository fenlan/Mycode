#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"data_structure.h"

/*
����һ�ý��и��ڵ���ֵ���
*/
TrieTree create_TrieTree()
{
	TrieTree pTree = (TrieTree)malloc(sizeof(TrieNode));
	pTree->count = 0;
	int i;
	for(i=0;i<MAX;i++)
		pTree->next[i] = NULL;
	return pTree;
}

/*
�����ַ���str���ֵ���pTree��
���ڲ����ܸı���ڵ㣬������ﲻ��Ҫ����pTree������
*/
void insert_TrieTree(TrieTree pTree,char *str)
{
	int i;
	TrieTree pCur = pTree;	//��ǰ���ʵĽڵ㣬��ʼָ����ڵ�
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		int id = str[i] - 'a';	//��λ���ַ�Ӧ���ڵ�λ��
		if(!pCur->next[id])
		{	//������ַ�Ӧ���ڵ�λ��Ϊ�գ����ַ����뵽��λ��
			int j;
			TrieNode *pNew = (TrieNode *)malloc(sizeof(TrieNode));
			if(!pNew)
			{
				printf("pNew malloc fail\n");
				exit(-1);
			}
			pNew->count = 1;
			for(j=0;j<MAX;j++)
				pNew->next[j] = NULL;
			//ָ����ƣ��Ƚ���һ���ַ�
			pCur->next[id] = pNew;
			pCur = pCur->next[id]; 
		}
		else
		{	//������ַ�Ӧ���ڵ�λ�ò��գ�������Ƚ���һ���ַ�
			pCur = pCur->next[id];
			pCur->count++;	//ÿ����һ���ַ�������ǰ׺��Ŀ�ͼ�1
		}
	}
}

/*
ͳ���ֵ���pTree����strΪǰ׺���ַ�������Ŀ
*/
int count_TrieTree(TrieTree pTree,char *str)
{
	int i;
	TrieTree pCur = pTree;
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		int id = str[i] - 'a';
		if(!pCur->next[id])
			return 0;
		else
			pCur = pCur->next[id];
	}
	return pCur->count;
}

/*
�����ֵ���
*/
void destroy_TrieTree(TrieTree pTree)
{
	int i;
	//�ݹ��ͷ�ÿ���ڵ���ڴ�
	for(i=0;i<MAX;i++)
		if(pTree->next[i])
			destroy_TrieTree(pTree->next[i]);
	free(pTree);
}