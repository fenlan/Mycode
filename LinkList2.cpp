#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType date;
	Node *next;
}Node, *LinkList;

bool CreateList_L(LinkList &L);                        //创建单链表L并逆序输入数据,并以0为结束

void TraverseList_L(LinkList &L);                      //遍历单链表L中的元素

void MaoPaoSort(LinkList &L);                          //将单链表L中的元素用冒泡法排序

int main()
{
	LinkList L;
	CreateList_L(L);
	TraverseList_L(L);
	MaoPaoSort(L);
	TraverseList_L(L);

	return 0;
}

bool CreateList_L(LinkList &L)
{
	ElemType InputElem;                                //接受用户输入的元素
	LinkList newNode;                                  //创建新结点
	L = (LinkList)malloc(sizeof(Node));
	if(!L)            return false;
	L->next = NULL;

	while(true)
	{
		scanf("%d", &InputElem);
		if(InputElem == 0)       break;
		else
		{
			newNode = (LinkList)malloc(sizeof(Node));
			newNode->next = L->next; L->next = newNode;
			newNode->date = InputElem;
		}
	}

	return true;
}

void TraverseList_L(LinkList &L)
{
	LinkList p;
	p = L;
	if((p->next) == NULL)      printf("EmptyList!");
	while(true)
	{
		p = p->next;
		if(!p)        break;
		else
			printf("%d ", p->date);
	}
	printf("\n");
}

void MaoPaoSort(LinkList &L)
{
	int i = 0, j = 0;
	int ListLength = 0;
	LinkList p;
	p = L;

	while(true)
	{
		if((p->next) == NULL)      break;
		else
		{
			p = p->next;
			ListLength++;
		}
	}

	for(i = 0;i<ListLength - 1;i++)
	{
		p = L;                                                  //重置p
		p = p->next;
		for(j = 0;j<ListLength - i - 1;j++)
		{
			if((p->date) > (p->next->date))
			{
				ElemType t = 0;
				t = p->date; p->date = p->next->date; p->next->date = t;
			}
			p = p->next;
		}
	}
}