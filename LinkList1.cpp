#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType date;
	Node *next;
}Node, *LinkList;

bool CreateList_L(LinkList &L, int n);                          
/*创建单链表L并逆序输入n个数到单链表中
 *创建成功返回true，创建失败返回false
 */

bool ListInsert_L(LinkList &L, int i, ElemType e);              
/*在带头结点的单链表L中第i个位置之前插入元素e
 *插入成功返回true，插入失败返回false
 */

bool ListDelete_L(LinkList &L, int i, ElemType &e);               
/*删除单链表中第i个元素并将值赋给e
 *删除成功返回true，删除失败返回false
 */

void TraverseList_L(LinkList &L);                               
//遍历单链表L中的元素

int main()
{
	int number = 0;
	LinkList L;
	ElemType e = 0;

	printf("输入创建链表结点个数\n");
	scanf("%d", &number);

	CreateList_L(L, number);
	ListInsert_L(L,3,9);
	ListDelete_L(L,3,e);
	ListDelete_L(L,1,e);
	ListDelete_L(L,1,e);
	ListDelete_L(L,1,e);
	ListDelete_L(L,1,e);
	ListDelete_L(L,1,e);
	printf("%d\n", e);
	TraverseList_L(L);
	return 0;
}

bool CreateList_L(LinkList &L, int n)
{
	int i = 0;
	LinkList newNode;
	L = (LinkList)malloc(sizeof(Node));         //生成头结点
	if(!L)
		return false;
	L->next = NULL;

	for (i = 0; i < n; ++i)
	{
		newNode = (LinkList)malloc(sizeof(Node));                    //生成新结点
		if(!newNode)
			return false;

		scanf("%d",&newNode->date);
		newNode->next = L->next; L->next = newNode;                     //将新结点插入到表头
	}

	return true;
}

bool ListInsert_L(LinkList &L, int i, ElemType e)
{
	int j = 0;
	LinkList p;                  
	LinkList newNode;               //新增结点
	p = L;

	while(p && j<i-1)               //找到插入点
	{
		p = p->next;
		j++;
	}
	if(!p || j>i-1)   return false;

	newNode = (LinkList)malloc(sizeof(Node));
	newNode->date = e;
	newNode->next = p->next; p->next = newNode;

	return true;
}

bool ListDelete_L(LinkList &L, int i, ElemType &e)
{
	int j = 0;
	LinkList p;
	LinkList q;
	p = L;

	while(p && j<i - 1)
	{
		p = p->next;
		j++;
	}

	if(!p || j>i - 1)     return false;
	q = p->next; p->next = q->next;
	e = q->date;
	free(q);

	return true;
}

void TraverseList_L(LinkList &L)
{
	LinkList p;
	p = L;

	if((p->next) == NULL)       printf("empty list!");
	while(true)
	{
		p = p->next;
		if(!p)       break;
		else
			printf("%d ", p->date);
	}
	printf("\n");
}
