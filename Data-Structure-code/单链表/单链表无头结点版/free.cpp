#include "sll_node.h"

/*�ͷ��ڴ溯��*/
void 
free_list(Node **phead)
{
	Node *psave;
	while(*phead != NULL)
	{
		psave = (*phead)->next;
		free(*phead);
		*phead = psave;
	}
}

