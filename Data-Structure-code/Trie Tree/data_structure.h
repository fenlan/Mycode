#define MAX 26	//�ַ����Ĵ�С

/*
�ֵ����Ĵ洢�ṹ
*/
typedef struct Node
{
	struct Node *next[MAX];	//ÿ���ڵ����������MAX���ַ�
	int count;				//�ԴӸ��ڵ㵽��ǰ�ڵ���ַ���Ϊ����ǰ׺���ַ�����Ŀ
}TrieNode,*TrieTree;

//����һ��ֻ�и��ڵ���ֵ���
TrieTree create_TrieTree();

//���ֵ����в����ַ���
void insert_TrieTree(TrieTree,char *);

//ͳ���ֵ������и�������ǰ׺���ַ�������Ŀ
int count_TrieTree(TrieTree ,char *);

//�����ֵ���
void destroy_TrieTree(TrieTree);
