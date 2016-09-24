#ifndef _MYSTACK_
#define _MYSTACK_

typedef int ElemType;

typedef struct Mystack
{
	ElemType * base;
	ElemType top;
	int StackSize;
}SqStack;

void InitStack(SqStack &S);
//�½���ջ

void Push(SqStack &S, ElemType elem);
//Ԫ����ջ

void Pop(SqStack &S, ElemType &elem);
//Ԫ�س�ջ����ֵ��elem

void GetTop(SqStack S, ElemType &elem);
//��ȡջ��Ԫ��

#endif