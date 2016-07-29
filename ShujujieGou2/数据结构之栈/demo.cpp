# include <stdlib.h>
# include "MyStack.h"
# include <iostream>
using namespace std;

int main(void)
{
	MyStack *pStack = new MyStack(5);

	pStack->push('h');
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o');

	pStack->stackTraverse(true);

	char elem = 0;
	pStack->pop(elem);

	pStack->stackTraverse(true);

	//pStack->clearStack();

	cout << pStack->stackLength() << endl;

	if (pStack->stackEmpty())
	{
		cout << "Õ»Îª¿Õ" << endl;
	}

	if (pStack->stackFull())
	{
		cout << "Õ»ÎªÂú" << endl;
	}

	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}