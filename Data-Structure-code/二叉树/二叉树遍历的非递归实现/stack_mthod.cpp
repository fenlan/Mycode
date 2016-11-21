#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

//����һ����ջ,������ָ���ջ��ָ��   
PSTACK create_stack()  
{  
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));  
	pS->pTop = (PNODE)malloc(sizeof(NODE));  
	if(NULL==pS || NULL==pS->pTop)  
	{  
	   printf("malloc failed");  
	   exit(-1);  
	}  
	else  
	{  
		pS->pBottom = pS->pTop;  
		pS->pBottom->pNext = NULL;  
	}  
	return pS;  
}  
   
//�жϸ�ջ�Ƿ�Ϊ��     
bool is_empty(PSTACK pS)  
{  
	if(pS->pTop == pS->pBottom)  
	   return true;  
	else  
	   return false;  
}  
  
//��pSָ��ָ���ջ��ѹ������val  
void push_stack(PSTACK pS,BTree val)  
{  
	PNODE pNew = (PNODE)malloc(sizeof(NODE));  
	if(NULL==pNew)  
	{  
		printf("malloc failed");  
		exit(-1);  
	}  
	else  
	{  
		pNew->data = val;  
		pNew->pNext = pS->pTop;  
		pS->pTop = pNew;  
	}  
	return ;  
}  
   
//��ջ���Ƴ����ݣ������Ƴ������ݱ�����pDataָ����ָ���λ��  
bool pop_stack(PSTACK pS,BTree *pData)  
{  
	if(is_empty(pS))  
	return false;  
	else  
	{  
		PNODE p = pS->pTop;  
		*pData = p->data;  
		pS->pTop = p->pNext;  
		free(p);  
		p = NULL;  
		return true;  
	}  
}  
  
//����ջ������ջ����ջ�����ջ�е�����  
void traverse_stack(PSTACK pS)  
{  
	PNODE pCurrent = pS->pTop;   
	printf("Now datas int the stack are:\n");  
	while(pCurrent != pS->pBottom)  
	{  
		printf("%d ",pCurrent->data);  
		pCurrent = pCurrent->pNext;  
	}  
	printf("\n");  
	return ;  
}  
   
//���ջ�������仹ԭΪ��ջ  
void clear_stack(PSTACK pS)  
{  
	if(is_empty(pS))  
		return ;  
	else  
	{  
		PNODE p = pS->pTop;  
		PNODE r = NULL;  
		while(p != pS->pBottom)  
		{  
			r = p->pNext;  
			free(p);  
			p = r;  
		}  
	pS->pTop = pS->pBottom;  
	}  
}  

//���ջ���գ�����ջ��Ԫ��,���ջ�գ����ؿ�ָ��
BTree getTop(PSTACK pS)
{
	if(!is_empty(pS))
		return pS->pTop->data;
	else
		return NULL;
}   