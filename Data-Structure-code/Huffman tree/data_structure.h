/*
�շ������Ĵ洢�ṹ����Ҳ��һ�ֶ������ṹ��
���ִ洢�ṹ���ʺϱ�ʾ����Ҳ�ʺϱ�ʾɭ�֡�
*/
typedef struct Node
{
	int weight;                //Ȩֵ
	int parent;                //���ڵ����ţ�Ϊ-1���Ǹ��ڵ�
	int lchild,rchild;         //���Һ��ӽڵ����ţ�Ϊ-1����Ҷ�ӽڵ�
}HTNode,*HuffmanTree;          //�����洢�շ������е����нڵ�
typedef char **HuffmanCode;    //�����洢ÿ��Ҷ�ӽڵ�ĺշ�������


//���ݸ���������Ȩֵ����һ�úշ�����
HuffmanTree create_HuffmanTree(int *,int);  

//�����нڵ���ѡ��Ȩֵ��С�ĸ��ڵ㣬�������������е���ŷ���
//�ú�����Ҫ�ǹ�select_minium��������
int min(HuffmanTree ,int);

//�����нڵ���ѡ��Ȩֵ��С���������ڵ㣬��������ŷֱ𱣴��ں�����������
void select_minium(HuffmanTree,int,int &,int &);

//��Ҷ�ӽڵ㵽���ڵ�������ÿ���ַ��ĺշ�������
void HuffmanCoding(HuffmanTree,HuffmanCode &,int);

//�Ӹ��ڵ㵽Ҷ�ӽڵ���ջ�ǵݹ�����շ�����,����Ҷ�ӽڵ�ĺշ�������
void HuffmanCoding2(HuffmanTree,HuffmanCode &,int);