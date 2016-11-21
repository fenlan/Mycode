#define M 7		//��ϣ�����еĳ���,����С�ڵ��ڱ�
typedef int ElemType;

/*
�ù�ϣ��������ӷ������ͻ����
*/
typedef struct Node	
{	//NodeΪ����ڵ�����ݽṹ
	ElemType data;
	struct Node *next;
}Node,*pNode;

typedef struct HashNode
{	//HashNodeΪ��ϣ���ÿ���۵����ݽṹ
	pNode first;	//firstָ������ĵ�һ���ڵ�
}HashNode,*HashTable;

//������ϣ��
HashTable create_HashTable(int);

//�ڹ�ϣ���в�������
pNode search_HashTable(HashTable, ElemType);

//�������ݵ���ϣ��
bool insert_HashTable(HashTable,ElemType);

//�ӹ�ϣ����ɾ������
bool delete_HashTable(HashTable,ElemType);

//���ٹ�ϣ��
void destroy_HashTable(HashTable,int);