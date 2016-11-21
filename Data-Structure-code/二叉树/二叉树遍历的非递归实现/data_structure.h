//����������ı�ʾ����
typedef struct BTNode
{
	char data;
	struct BTNode *pLchild;
	struct BTNode *pRchild;
}BTNode, *BTree;


//����һ�ö�����
BTree create_tree();
//�ǵݹ�ʵ�ֶ�������ǰ�����
void pre_traverse(BTree);
//�ǵݹ�ʵ�ֶ������Ķ��������
void in_traverse(BTree);
//�ǵݹ�ʵ�ֶ������ĺ������
void beh_traverse(BTree);


//����ջ�ı�ʾ����
typedef struct Node  
{  
	BTree data;  
	struct Node *pNext;  
}NODE,*PNODE;  

typedef struct Stack  
{  
	PNODE pTop;  
	PNODE pBottom;  
}STACK,*PSTACK; 

//������ջ�ĺ���
PSTACK create_stack();  
//��ջ����
void push_stack(PSTACK,BTree);  
//����ջ
void traverse_stack(PSTACK);  
//��ջ����
bool pop_stack(PSTACK,BTree *); 
//�ж�ջ�պ��� 
bool is_empty(PSTACK);  
//���ջ
void clear_stack(PSTACK);    
//ȡջ��Ԫ��
BTree getTop(PSTACK);   