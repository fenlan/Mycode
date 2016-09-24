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
//新建空栈

void Push(SqStack &S, ElemType elem);
//元素入栈

void Pop(SqStack &S, ElemType &elem);
//元素出栈并赋值给elem

void GetTop(SqStack S, ElemType &elem);
//获取栈顶元素

#endif