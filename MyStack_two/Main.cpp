#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>

void Translate(SqStack &S, ElemType number, int JinZhi);
//JinZhi Ϊ��Ҫת���Ľ���

int main ()
{
	ElemType number = 0;                  //Ҫת������
	int JinZhi = 0;                       //Ҫת���Ľ���
	SqStack S;

	InitStack(S);

	printf("�ֱ�����Ҫת����ʮ�������ͽ���\n");
	scanf("%d %d", &number, &JinZhi);

	Translate(S, number, JinZhi);

	system("pause");
	return 0;
}

void Translate(SqStack &S, ElemType number, int JinZhi)
{
	ElemType elem;

	while(number)
	{
		Push(S, number % JinZhi);
		number = number /JinZhi;
	}

	while(0 != S.top)
	{
		Pop(S, elem);
		printf("%d", elem);
	}
	printf("\n");
}