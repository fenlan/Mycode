#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>

void Translate(SqStack &S, ElemType number, int JinZhi);
//JinZhi 为所要转换的进制

int main ()
{
	ElemType number = 0;                  //要转换的数
	int JinZhi = 0;                       //要转换的进制
	SqStack S;

	InitStack(S);

	printf("分别输入要转换的十进制数和进制\n");
	scanf("%d %d", &number, &JinZhi);

	Translate(S, number, JinZhi);

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
		printf("%d ", elem);
	}
	printf("\n");
}