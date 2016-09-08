#include <stdio.h>
#include <stdlib.h>

typedef double ElemType;
typedef struct Node
{
	ElemType The_Coefficient_subtraction = 0;
	ElemType The_Coefficient = 0;
	int The_Exponent = 0;
	Node *next;
}Node, *LinkList;

bool CreateList_L(LinkList &L, int n);
/*创建单链表L
 *同时输入多项式的项数，并逐个输入每个项的系数和指数
 *创建成功返回true，创建失败返回false
 */

bool LinkListInsertEnd_L(LinkList &L, ElemType The_Coefficient, ElemType The_Coefficient_subtraction, int The_Exponent);
//将The_Coefficient 和 The_Exponent 合成一个新结点添加到L之后，

void MaoPaoSort(LinkList &L);
//通过对多项式指数进行冒泡排序使输出多项式按指数递减输出

bool ListDelete_L(LinkList &L);
//删除L结点之后一个结点

int main()
{
	int i = 0, j = 0;
	int Is_Plus = 1;
	int Polynomial_one_Length = 0, Polynomial_two_Length = 0;
	LinkList p;
	LinkList Polynomial_one, Polynomial_two;
	ElemType The_Coefficient = 0, The_Coefficient_subtraction = 0;
	int The_Exponent = 0;


	printf("请输入第一个多项式的项数：\n");
	scanf("%d", &Polynomial_one_Length);
	CreateList_L(Polynomial_one, Polynomial_one_Length);

	printf("请输入第二个多项式的项数：\n");
	scanf("%d", &Polynomial_two_Length);
	CreateList_L(Polynomial_two, Polynomial_two_Length);

	for (i = 0;i<Polynomial_two_Length;i++)                        //此 for 循环是进行两个多项式相加操作
	{
		p = Polynomial_one;
		p = p->next;
		Polynomial_two = Polynomial_two->next;
		The_Coefficient_subtraction = The_Coefficient = Polynomial_two->The_Coefficient;
		The_Exponent = Polynomial_two->The_Exponent;

		bool Is_Equal = false;
		for (j = 0;j<Polynomial_one_Length-1;j++)
		{
			//printf("%.2lf %.2lf\n", p->The_Coefficient_subtraction, The_Coefficient_subtraction);
			if (The_Exponent == p->The_Exponent)
			{
				p->The_Coefficient += The_Coefficient;
				p->The_Coefficient_subtraction -= The_Coefficient;
				//printf("%.2lf\n", p->The_Coefficient_subtraction);
				Is_Equal = true;
				p = p->next;
				break;
			}

			p = p->next;
		}
		if (The_Exponent == p->The_Exponent)        //这一步是考虑到上一步的for循环当循环到最后一个之前退出循环后判断最后一个是不是满足条件
		{                                     //之所以上一步的for循环没有循环最后一个结点是为了保留最后 p 所表示的是最后一个结点，而不是NULL
			p->The_Coefficient += The_Coefficient;      //当最后一个节点 p 不满足条件时可将 p 传给函数LinkListInsertEnd_L();
			p->The_Coefficient_subtraction -= The_Coefficient;
			Is_Equal = true;
		}

		if (false == Is_Equal)
		{
			LinkListInsertEnd_L(p, The_Coefficient, -The_Coefficient_subtraction, The_Exponent);
			Polynomial_one_Length++;
		}


	}

	MaoPaoSort(Polynomial_one);                                    //用冒泡法将相加所得的多项式按指数递减顺序排列  

	printf("输入需要进行的操作\n");
	printf("相加：1          相减：0\n");
	scanf("%d", &Is_Plus);

	p = Polynomial_one;
	if (Is_Plus)
	{
		for (i = 0;i<Polynomial_one_Length;i++)                        //将之前两多项式相加所得的系数为零的项删掉
		{                                                              
			if (0 == p->next->The_Coefficient)
			{
				ListDelete_L(p);
				Polynomial_one_Length--;
			}
			else
				p = p->next;
		}

		p = Polynomial_one;
		printf("相加得到多项式的项数：%d\n", Polynomial_one_Length);                          //输出所加得到多项式的项数
		for (i = 0;i<Polynomial_one_Length;i++)
		{
			p = p->next;
			printf("%.1lfX%d ", p->The_Coefficient, p->The_Exponent);
		}
	}

	else
	{
		for (i = 0;i<Polynomial_one_Length;i++)                        //将之前两多项式相减所得的系数为零的项删掉
		{                                                              
			if (0 == p->next->The_Coefficient_subtraction)
			{
				ListDelete_L(p);
				Polynomial_one_Length--;
			}
			else
				p = p->next;
		}

		p = Polynomial_one;
		printf("相减得到多项式的项数：%d\n", Polynomial_one_Length);                          //输出所加得到多项式的项数
		for (i = 0;i<Polynomial_one_Length;i++)
		{
			p = p->next;
			printf("%.1lfX%d ", p->The_Coefficient_subtraction, p->The_Exponent);
		}
	}

	printf("\n");

	free(Polynomial_one);
	free(Polynomial_two);
	return 0;
}

bool CreateList_L(LinkList &L, int n)
{
	int i = 0;
	ElemType InputCoefficient = 0;
	int InputExponent = 0;
	LinkList newNode;

	L = (LinkList)malloc(sizeof(Node));
	if (!L)              return false;
	L->next = NULL;

	printf("请一次输入多项式每项的系数和指数\n");
	for (i = 0;i<n;i++)
	{
		newNode = (LinkList)malloc(sizeof(Node));
		if(!newNode)                return false;

		scanf("%lf %d", &InputCoefficient, &InputExponent);
		if(InputExponent < 0)
		{
			printf("请输入大于等于0的指数\n");
			scanf("%lf %d", &InputCoefficient, &InputExponent);
		}

		newNode->The_Coefficient = newNode->The_Coefficient_subtraction = InputCoefficient;
		newNode->The_Exponent = InputExponent;
		newNode->next = L->next; L->next = newNode;
	}

	return true;
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
			if((p->The_Exponent) < (p->next->The_Exponent))
			{
				ElemType t = 0;
				int t1 = 0;
				t1 = p->The_Exponent; p->The_Exponent = p->next->The_Exponent; p->next->The_Exponent = t1;

				t = p->The_Coefficient; p->The_Coefficient = p->next->The_Coefficient; p->next->The_Coefficient = t;

				t = p->The_Coefficient_subtraction; 
				p->The_Coefficient_subtraction = p->next->The_Coefficient_subtraction; 
				p->next->The_Coefficient_subtraction = t;
			}
			p = p->next;
		}
	}
}

bool LinkListInsertEnd_L(LinkList &L, ElemType The_Coefficient, ElemType The_Coefficient_subtraction, int The_Exponent)
{
	LinkList EndNode;
	EndNode = (LinkList)malloc(sizeof(Node));
	if(!EndNode)               return false;

	EndNode->The_Coefficient = The_Coefficient; EndNode->The_Exponent = The_Exponent; 
	EndNode->The_Coefficient_subtraction = The_Coefficient_subtraction;
	EndNode->next = L->next; L->next = EndNode;

	return true;
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