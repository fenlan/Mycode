#include "sll_node.h"

/*��ʾ����*/
void 
show(Node *root)
{
	Node *current;    
	if(root == NULL)
		printf("No data entered.");

	current = root;
	while(current != NULL)
	{
		printf(" %d ",current->value);
		current = current->next;
	}
}	

