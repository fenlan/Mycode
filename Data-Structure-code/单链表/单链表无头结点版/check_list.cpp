#include "sll_node.h"

/*�����������������������Ƿ��������е������ظ�*/
bool
check(Node *root,int value)
{
	Node *current;
	current = root;
	while(current != NULL)
	{
		if(current->value != value)
			current = current->next;
		else
			break;
	}

	if(current == NULL)
		return true;       //���������û���������е������ظ�������true
	else 
		return false;
}
