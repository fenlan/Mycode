#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

//����һ�ö�����
BTree create_tree()
{
	BTree pA = (BTree)malloc(sizeof(BTNode));
	BTree pB = (BTree)malloc(sizeof(BTNode));
	BTree pD = (BTree)malloc(sizeof(BTNode));
	BTree pE = (BTree)malloc(sizeof(BTNode));
	BTree pC = (BTree)malloc(sizeof(BTNode));
	BTree pF = (BTree)malloc(sizeof(BTNode));
	
	pA->data = 'A';
	pB->data = 'B';
	pD->data = 'D';
	pE->data = 'E';
	pC->data = 'C';
	pF->data = 'F';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = pE;
	pD->pLchild = pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pC->pLchild = pF;
	pC->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;	
	
	return pA;
}

/*
ǰ������ķǵݹ�ʵ��
*/
void pre_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //����һ����ջ
	BTree node_pop;                 //���������ջ�ڵ�
	BTree pCur = pTree;             //��������ָ��ǰ���ʵĽڵ��ָ��

	//ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
	while(pCur || !is_empty(stack))
	{
		//�Ӹ��ڵ㿪ʼ�������ǰ�ڵ㣬��������ջ��
		//ͬʱ��������Ϊ��ǰ�ڵ㣬ֱ����û�����ӣ�ֱ��ǰ�ڵ�ΪNULL
		printf("%c ", pCur->data);
		push_stack(stack,pCur);
		pCur = pCur->pLchild;
		//�����ǰ�ڵ�pCurΪNULL��ջ���գ���ջ���ڵ��ջ��
		//ͬʱ�����Һ���Ϊ��ǰ�ڵ�,ѭ���жϣ�ֱ��pCur��Ϊ��
		while(!pCur && !is_empty(stack))
		{
			pCur = getTop(stack);
			pop_stack(stack,&node_pop);
			pCur = pCur->pRchild;			
		}
	}
}

/*
��������ķǵݹ�ʵ��
*/
void in_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //����һ����ջ
	BTree node_pop;                 //���������ջ�ڵ�
	BTree pCur = pTree;             //����ָ��ǰ���ʵĽڵ��ָ��

	//ֱ����ǰ�ڵ�pCurΪNULL��ջ��ʱ��ѭ������
	while(pCur || !is_empty(stack))
	{
		if(pCur->pLchild)
		{
			//���pCur�����Ӳ�Ϊ�գ�������ջ������������Ϊ��ǰ�ڵ�
			push_stack(stack,pCur);
			pCur = pCur->pLchild;
		}
		else
		{
			//���pCur������Ϊ�գ������pCur�ڵ㣬�������Һ�����Ϊ��ǰ�ڵ㣬�����Ƿ�Ϊ��
			printf("%c ", pCur->data);
			pCur = pCur->pRchild;
			//���Ϊ�գ���ջ���գ���ջ���ڵ��ջ��������ýڵ㣬
			//ͬʱ�������Һ�����Ϊ��ǰ�ڵ㣬�����жϣ�ֱ����ǰ�ڵ㲻Ϊ��
			while(!pCur && !is_empty(stack))
			{
				pCur = getTop(stack);
				printf("%c ",pCur->data);	
				pop_stack(stack,&node_pop);
				pCur = pCur->pRchild;
			}
		}
	}
}

/*
��������ķǵݹ�ʵ��
*/
void beh_traverse(BTree pTree)
{
	PSTACK stack = create_stack();  //����һ����ջ
	BTree node_pop;          //���������ջ�Ľڵ�
	BTree pCur;              //����ָ�룬ָ��ǰ�ڵ�
	BTree pPre = NULL;       //����ָ�룬ָ����һ�����ʵĽڵ�

	//�Ƚ����ĸ��ڵ���ջ
	push_stack(stack,pTree);  
	//ֱ��ջ��ʱ������ѭ��
	while(!is_empty(stack))
	{
		pCur = getTop(stack);   //��ǰ�ڵ���Ϊջ���ڵ�
		if((pCur->pLchild==NULL && pCur->pRchild==NULL) || 
			(pPre!=NULL && (pCur->pLchild==pPre || pCur->pRchild==pPre)))
		{
			//�����ǰ�ڵ�û�����Һ��ӣ����������ӻ��к��ӣ����Ѿ������������
			//��ֱ������ýڵ㣬�����ջ��������Ϊ��һ�����ʵĽڵ�
			printf("%c ", pCur->data);
			pop_stack(stack,&node_pop);
			pPre = pCur;
		}
		else
		{
			//��������������������,�����Һ�������������ջ
			if(pCur->pRchild != NULL)
				push_stack(stack,pCur->pRchild);
			if(pCur->pLchild != NULL)
				push_stack(stack,pCur->pLchild);
		}
	}
}
