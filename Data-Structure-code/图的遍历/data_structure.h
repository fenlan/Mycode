#define NUM 8          //ͼ�ж���ĸ���

/*
���ڽӱ���Ϊͼ�Ĵ洢�ṹ
���ڽӱ��У���һ��һά����洢ͼ�е�ÿ���������Ϣ��
ͬʱΪÿ�����㽨��һ�������������еĽڵ㱣�������ڸö����ϵı߻򻡵���Ϣ
*/
typedef struct node
{	//�����е�ÿ���ڵ㣬���������ڸýڵ��ϵı߻򻡵���Ϣ
	int vertex;          //������ͼ�б�ʾ�û���ָ��Ķ��㣨����ͷ����λ�ã�
				         //������ͼ�б�ʾ�����ڸñ��ϵ���һ�������λ��
	struct node *pNext;  //ָ����һ�������ڸö����ϵĻ����
}Node;
typedef struct head
{	//�����е�ÿ��Ԫ�أ�����ͼ��ÿ������������Ϣ
	char data;          //�����������
	Node *first;        //������ͼ�У�ָ���Ըö���Ϊ��β�ĵ�һ����
						//������ͼ�У�ָ�������ڸö����ϵĵ�һ����
}Head,*Graph;           //��̬�������鱣��ÿ������������Ϣ


//����ͼ��������Ӧ��ͼ
Graph create_graph();

//����ͼ��ָ����Ŷ���ĵ�һ���ڽӵ�
int first_vertex(Graph,int);

//����ͼ��ָ����Žڵ����һ���ڽӵ�
int next_vertex(Graph,int,int);

//��ָ�����������������ȱ�����ͨͼ
void DFS(Graph, int);

//��ָ���������������ȱ���ͼ,��������ͨͼҲ�����Ƿ���ͨͼ
void DFS_traverse(Graph,int);

//��ָ�����������������ȱ�����ͨͼ
void BFS(Graph,int);

//��ָ���������������ȱ���ͼ,��������ͨͼҲ�����Ƿ���ͨͼ
void BFS_traverse(Graph,int);



/*
��ʽ���еĴ洢�ṹ
*/
typedef struct NODE
{	//�����е�ÿ���ڵ�
	int data;
	struct NODE *pNext;
}NODE,*PNODE;
typedef struct Queue
{	//ʼ��ָ��ӵ�ͷ����β��
	PNODE front;  //��ͷָ��
	PNODE rear;   //��βָ��
}QUEUE,*PQUEUE;


//������һ���ն���
PQUEUE create_queue();

//�ж϶����Ƿ�Ϊ��
bool is_empty(PQUEUE);

//���Ӻ���
void en_queue(PQUEUE, int);

//���Ӻ���
bool de_queue(PQUEUE,int *);

//���ٶ���
void destroy_queue(PQUEUE);

//��������
void traverse_queue(PQUEUE);






