# include <iostream>
# include <stdlib.h>
# include "MyQueue.h"
# include "Customer.h"
using namespace std;

int main(void)
{
	MyQueue *p = new MyQueue(4);
	Customer c1("张三",20);
	Customer c2("李四",30);
	Customer c3("王五",25);

	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);

	p->QueueTraverse();

	Customer c4("",0);
	p->DeQueue(c4);
	c4.printInfo();

	system("pause");
	return 0;
}