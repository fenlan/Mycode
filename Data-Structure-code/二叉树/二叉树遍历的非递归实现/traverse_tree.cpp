#include<stdio.h>
#include<stdlib.h>
#include"data_structure.h"

int main()
{
	BTree pTree = create_tree();

	printf("�ǵݹ�ʵ��ǰ����������");
	pre_traverse(pTree);
	printf("\n");

	printf("�ǵݹ�ʵ��������������");
	in_traverse(pTree);
	printf("\n");

	printf("�ǵݹ�ʵ�ֺ�����������");
	beh_traverse(pTree);
	printf("\n");
	
	return 0;
}






















