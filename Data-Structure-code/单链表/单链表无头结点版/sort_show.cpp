#include "sll_node.h"

/*ð�ݷ������������������ı�ڵ�λ�ã�ֻ�ı�ڵ������ݵĴ洢λ��*/
void 
sort(Node *root)
{
	Node *current;
	Node *s;
	
	for(current = root;current->next != NULL;current = current->next)
	{
		for(s = root;s->next != NULL;s = s->next)
		{
			
			if(s->value > s->next->value)
			{
				int temp;
				temp = s->value;
				s->value = s->next->value;
				s->next->value = temp;
			}
		}
	}

}