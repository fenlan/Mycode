#include<stdio.h>
#include<stdlib.h>
#include "data_structure.h"

/*
����һ������Ϊn�Ĺ�ϣ��
*/
HashTable create_HashTable(int n)
{
	int i;
	HashTable hashtable = (HashTable)malloc(n*sizeof(HashNode));
	if(!hashtable)
	{
		printf("hashtable malloc faild,program exit...");
		exit(-1);
	}

	//����ϣ���ÿ�
	for(i=0;i<n;i++)
		hashtable[i].first = NULL;
//	memset(hashtable,0,sizeof(hashtable));

	return hashtable;
}

/*
�ڹ�ϣ���в�������data�����ҳɹ��򷵻��������е�λ�ã�
���Ҳ��ɹ��򷵻�NULL�����й�ϣ����ΪH(key)=key%M
*/
pNode search_HashTable(HashTable hashtable, ElemType data)
{
	if(!hashtable)
		return NULL;

	//��д�������˳ɹ��벻�ɹ��������
	pNode pCur = hashtable[data%M].first;
	while(pCur && pCur->data != data)
		pCur = pCur->next;

	return pCur;
}

/*
���ϣ���в�������data�����data�Ѵ��ڣ��򷵻�fasle��
���򣬲����Ӧ�������󲢷���true�����й�ϣ����ΪH(key)=key%M
*/
bool insert_HashTable(HashTable hashtable,ElemType data)
{
	//����Ѿ����ڣ�����false
	if(search_HashTable(hashtable,data))
		return false;

	//����Ϊdata����ռ�
	pNode pNew = (pNode)malloc(sizeof(Node));
	if(!pNew)
	{
		printf("pNew malloc faild,program exit...");
		exit(-1);
	}
	pNew->data = data;
	pNew->next = NULL;

	//���ڵ���뵽��Ӧ��������
	pNode pCur = hashtable[data%M].first;
	if(!pCur)	//����λ��Ϊ�����һ���ڵ�����
		hashtable[data%M].first = pNew;
	else	//����λ�ò��������һ���ڵ�����
	{	//ֻ����pCur->next�ſ��Խ�pNew�ڵ����������ϣ�
		//��pCur�����������ϣ�����������pCur��
		//pCur��Ȼ����ָ�������е�ĳ���ڵ㣬������������������
		while(pCur->next)
			pCur = pCur->next;
		pCur->next = pNew;
	}

	return true;
}

/*
�ӹ�ϣ����ɾ������data�����data�����ڣ��򷵻�fasle��
����ɾ��֮������true�����й�ϣ����ΪH(key)=key%M
*/
bool delete_HashTable(HashTable hashtable,ElemType data)
{
	//���û���ҵ�������false
	if(!search_HashTable(hashtable,data))
		return false;
	//����һ�����ڣ��ҵ�ɾ��֮
	pNode pCur = hashtable[data%M].first;
	pNode pPre = pCur;	//��ɾ�ڵ��ǰһ���ڵ�,��ʼֵ��pCur��ͬ
	if(pCur->data == data)	//��ɾ�ڵ�������ĵ�һ���ڵ�����
		hashtable[data%M].first = pCur->next;
	else
	{	//��ɾ�ڵ㲻�ǵ�һ���ڵ�����
		while(pCur && pCur->data != data)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		pPre->next = pCur->next;
	}
	free(pCur);
	pCur = 0;
	return true;
}

/*
���ٲ���Ϊn�Ĺ�ϣ��
*/
void destroy_HashTable(HashTable hashtable,int n)
{
	int i;
	//����������ͷ�
	for(i=0;i<n;i++)
	{
		pNode pCur = hashtable[i].first;
		pNode pDel = NULL;
		while(pCur)
		{
			pDel = pCur;
			pCur = pCur->next;
			free(pDel);
			pDel = 0;
		}
	}
	//����ͷŹ�ϣ��
	free(hashtable);
	hashtable = 0;
}