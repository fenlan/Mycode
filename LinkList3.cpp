/*程序为解决约瑟夫环问题
 *缺陷：ListDelete_L(LinkList &L) 函数删除的是 L结点的后一结点，而不是L结点
 *     导致67--91行代码太复杂。
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node
{
	ElemType number;
	ElemType password;
	Node *next;
}Node, *LinkList;

LinkList CreateList_L(int Element_quantity);      
/*创建循环链表
 *Element_number 为用户需要创建循环链表元素个数
 */

bool ListDelete_L(LinkList &L);
//删除L结点之后一个结点

int main()
 {
 	
 	int i = 0, j = 0, people_number = 0;
 	int password = 0;
 	int people_quantity = 0;
 	LinkList people;
 	LinkList p;
 	LinkList q;

 	printf("------约瑟夫问题解决方法------\n");
 	printf("请输入人数个数:\n");
 	scanf("%d", &people_quantity);

 	people = CreateList_L(people_quantity);
 
 	printf("依次输入每个人的密码\n");

	p = people;
	i = 0;
	while (i<people_quantity)
	{
		int password = 0;
		scanf("%d", &password);

		if (password <= 0)
		{
			printf("请输入大于0的数\n");
			continue;
		}

		else
		{
			p->password = password;
			p = p->next;
			i++;
		}
	}
	
	printf("请输入初始密码：");
	scanf("%d", &password);

	p = people;
	for (i = 0;i<people_quantity;i++)                  //67--91行代码不简洁，没有可读性，需要改善
	{
		if (password == 1)                             //当password为1时不适用于83---88行代码通式
		{
			password = p->password;                    //将当前结点的值赋给参数，并在79行使用该参数
			people_number = p->number;

			q = p;                                     //寻找当前结点的上一个结点并做删除处理
			while(q->next != p)
				q = q->next;

			ListDelete_L(q);
			printf("%d ", people_number);
			continue;
		}

		for (j = 0;j<password-2;j++)                    //其中 password-2 用于处理 LinkDelete_L(LinkList &L) 只能删除L结点之后的一个结点缺陷
			p = p->next;

		password = p->next->password;
		people_number = p->next->number;
		q = p; ListDelete_L(q); p = p->next;

		printf("%d ", people_number);
	}

	printf("\n");
	
 	free(people);
	
 	return 0;
 }

 LinkList CreateList_L(int Element_quantity)
 {
 	int i = 0, j = 0;
 	LinkList node_Head = NULL;
 	LinkList node_tail = NULL;
 	LinkList node_new;
 	//LinkList p;           //test code

 	node_Head = (LinkList)malloc(sizeof(Node));
 	if(!node_Head)            exit(0);

 	node_Head->number = ++j;
 	node_Head->next = node_Head;                  //初始化一个结点，使其首尾相接
 	node_tail = node_Head;                        //此时链表头也是尾

 	for (i = 0;i<Element_quantity - 1;i++)
 	{
 		node_new = (LinkList)malloc(sizeof(Node));
 		if(!node_new)         exit(0);

 		node_new->number = ++j;
 		node_new->next = node_Head;                //将新添加的结点指向链表首
 		node_tail->next = node_new;                //将之前的尾结点指向新结点
 		node_tail = node_new;                      //将尾结点更新为新结点
 	}
 	/*
 	p = node_Head;             //test code
 	for (i = 0;i<Element_quantity;i++)
 	{
 		printf("%d\n", p->number);
 		p = p->next;
 	}
 	*/
 	return node_Head;
 }

 bool ListDelete_L(LinkList &L)
 {
 	LinkList p;
 	LinkList q;
 	p = L;

 	if (!p)      return false;
 	q = p->next; p->next = q->next;
 	free(q);

 	return true;
 }