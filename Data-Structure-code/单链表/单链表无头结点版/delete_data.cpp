#include "sll_node.h"

/*ɾ���ڵ㺯��*/
void 
delete_data(Node **phead,int delete_value)
{
	Node *current;
	Node *previous;
	Node *next;
	Node *pt;

	current = *phead;
	previous = NULL;

	while(current->value != delete_value)
	{
		previous = current;
		current = current->next;
		next = current->next;
	}

	if(previous == NULL)
		*phead = current->next;
	else
		previous->next = next; 	
	pt = current;
	free(pt);
}