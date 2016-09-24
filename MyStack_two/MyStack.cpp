#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 50

void InitStack(SqStack &S)
{
	S.base = (ElemType *)malloc(STACKSIZE * sizeof(ElemType));
	if (!S.base)     exit(0);
	S.top = 0;
	S.StackSize = STACKSIZE;
}

void Push(SqStack &S, ElemType elem)
{
	if (S.top >= S.StackSize){
		S.base = (ElemType *)realloc(S.base, (S.StackSize + STACKSIZE) * sizeof(ElemType));
		if (!S.base)      exit(0);
		S.StackSize += STACKSIZE;
	}
	S.base[S.top++] = elem;
}

void Pop(SqStack &S, ElemType &elem)
{
	if (0 == S.top)        printf("栈已空，没有元素可出栈\n");
	else 
		elem = S.base[--S.top];
}

void GetTop(SqStack S, ElemType &elem)
{
	if (0 == S.top)          printf("空栈\n");
	else
		elem = S.base[S.top - 1];	
}