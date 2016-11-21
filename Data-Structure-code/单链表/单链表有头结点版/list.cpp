/**************************************************************************************************************
����Ϊ����������㷨��������Ϊ������
������ͷָ��Ϊ������ͷָ��ָ��ͷ�ڵ㣬ͷ�ڵ�ָ���׽ڵ㣬�Դ����ƣ�ֱ��β�ڵ㡣
ͷ�ڵ��в�������ݣ�ֻ���ָ���׽ڵ��ָ�룬
����ͷ�ڵ��Ŀ����Ϊ�˷��������Ĳ��������������ͷ�ڵ㣬����ֱ����ͷָ��ָ���׽ڵ㣬
�����ڶ�ͷָ���Ľڵ���в���ɾ������ʱ�ͻ��������ڵ���иò���ʱ������ͬ����Ҫ��Ϊһ���������������
**************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

PNODE create_list();       
void traverse_list(PNODE);
bool is_empty(PNODE);     
int length_list(PNODE); 
void sort_list(PNODE);    
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void clear_list(PNODE);

int main(void)
{
	int len;
	int data_del;
	PNODE pHead = NULL;

	//���������������
 	pHead = create_list();
	traverse_list(pHead);

	//�������ȣ������
	len = length_list(pHead);
	if(!is_empty(pHead))
		printf("the length of the list is:%d\n",len);
	
	//�������в������ݣ������±������
	if(insert_list(pHead,3,78))
		printf("insert succeed,");
	else
		printf("insert failed,");
	traverse_list(pHead);

	//��������ɾ�����ݣ������±������
	if(delete_list(pHead,3,&data_del))
		{
		  printf("delete succeed,the deleted data is:%d\n",data_del);
		}
	else
		printf("delete failed,");
	traverse_list(pHead);
	
	//�������������±������
	sort_list(pHead);
	printf("After sorted,");
	traverse_list(pHead);	
	
	//���������������������������
	clear_list(pHead);
	printf("After cleared,");
	traverse_list(pHead);	
	return 0;
}

/*
  ����һ������,������ͷָ��
*/
PNODE create_list()
{
	int val;
	PNODE pHead =(PNODE)malloc(sizeof(NODE));
	PNODE pCurrent = pHead;
	pCurrent->pNext = NULL;
	if(NULL == pHead)
	{
		printf("pHead malloc failed!");
		exit(-1);
	}
	printf("Input first data(q to quit):");
	while(scanf("%d",&val)==1)
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("pNew malloc failed!");
			exit(-1);
		}
		pNew->data = val;
		pCurrent->pNext = pNew;
		pNew->pNext = NULL;
		pCurrent = pNew;
		printf("Input next data(q to quit):");
	}

	return pHead;	
}

/*
��������
*/
void traverse_list(PNODE pHead)
{
	PNODE pCurrent = pHead->pNext;
	printf("now dataes in the list are:\n");
	while(pCurrent != NULL)
	{	
		printf("%d ",pCurrent->data);
		pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}

/*
�ж������Ƿ�Ϊ��
*/
bool is_empty(PNODE pNode)
{
	if(NULL == pNode->pNext)
		return true;
	else 
		return false;
}

/*
�������ȣ����ڵ�������������ͷ�ڵ㣩
*/
int length_list(PNODE pNode)
{
	int count = 0;
	PNODE pCurrent = pNode->pNext;
	while(pCurrent != NULL)
	{
		count++;
		pCurrent = pCurrent->pNext;		
	}

	return count;
}

/*
ð�ݷ�����������
*/
void sort_list(PNODE pHead)
{
	PNODE p,q;
	int temp;
	for(p=pHead->pNext;p!=NULL;p=p->pNext)
	    for(q=p->pNext;q!=NULL;q=q->pNext)
		{
		   if(p->data>q->data)
	              {
			 temp = p->data;
			 p->data = q->data;
			 q->data = temp;
		      }
		}

	return ;
}

/*
�ڵ�pos���ڵ�ĺ������һ���µĽڵ㣬�ýڵ��е�����Ϊval
*/
bool insert_list(PNODE pHead,int pos,int val)
{
	int i = 0;
	PNODE p = pHead;

        //iΪ0ʱ��pָ���0���ڵ㣨����ָû��ʵ�����ݵ�ͷ�ڵ㣬����������ڵ���������
	//iΪ1ʱ��pָ���1���ڵ㣬iΪ����p��ָ��ڼ����ڵ�
	while(p!=NULL && i<pos)
	{
	   p = p->pNext;
	   i++;
	}

	//��pos��ֵ����������ʱ���������������
	if(i>pos || p==NULL)
	   return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
	   printf("pNew malloc failed!");
	   exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;

	return true;
}

/*
ɾ����pos���ڵ㣬����ɾ�������ݱ�����pDataָ����ָ���λ��
*/
bool delete_list(PNODE pHead,int pos,int *pData)
{
	int i = 0;
	PNODE p = pHead;

	//p����ָ���pos���ڵ�ǰ��Ľڵ�
	//�����������ֱ��Ϊwhile(p!=NULL && i<pos)��if(i>pos || p==NULL)����p����ָ���pos���ڵ㣬
	//������Ϊ�ò�����pos���ڵ�ǰ����Ǹ��ڵ㣬����޷���posǰ�������ڵ���������
	while(p->pNext!=NULL && i<pos-1)
	{
	   p = p->pNext;
	   i++;
	}

	//��pos��ֵ����������ʱ���������������
	if(i>pos-1 || p->pNext==NULL)
	   return false;

	PNODE q = p->pNext;
	*pData = q->data;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}

/*
���������ʹ����ֻʣ��ͷ�ڵ㣨ͷ�ڵ���û�����ݣ�
*/
void clear_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	PNODE r = NULL;
	while(p != NULL)
	{
	   r = p->pNext;
	   free(p);
	   p = r;
	}
	pHead->pNext = NULL;
	return ;
}
