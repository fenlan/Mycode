#include "sll_node.h"

/*�ڵ��������*/
unsigned int 
count(Node *root)
{
	unsigned int count = 0;
	while(root != NULL)
	{
		++count;
		root = root->next;
	}
	
	return count;
}