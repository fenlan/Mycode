/*******************************
			��ϣ��
Author:��ͤ���� Date:2014-03-07
Email:zyb_maodun@163.com
*******************************/
#include<stdio.h>
#include "data_structure.h"

int main()
{
	int len = 15;	//��ϣ�����༴���в۵���Ŀ
	printf("We set the length of hashtable %d\n",len);

	//������ϣ����������
	HashTable hashtable = create_HashTable(len);
	if(insert_HashTable(hashtable,1))
		printf("insert 1 success\n");
	else 
		printf("insert 1 fail,it is already existed in the hashtable\n");
	if(insert_HashTable(hashtable,8))
		printf("insert 8 success\n");
	else 
		printf("insert 8 fail,it is already existed in the hashtable\n");
	if(insert_HashTable(hashtable,3))
		printf("insert 3 success\n");
	else 
		printf("insert 3 fail,it is already existed in the hashtable\n");
	if(insert_HashTable(hashtable,10))
		printf("insert 10 success\n");
	else 
		printf("insert 10 fail,it is already existed in the hashtable\n");
	if(insert_HashTable(hashtable,8))
		printf("insert 8 success\n");
	else 
		printf("insert 8 fail,it is already existed in the hashtable\n");

	//��������
	pNode pFind1 = search_HashTable(hashtable,10);
	if(pFind1)
		printf("find %d in the hashtable\n",pFind1->data);		
	else 
		printf("not find 10 in the hashtable\n");
	pNode pFind2 = search_HashTable(hashtable,4);
	if(pFind2)
		printf("find %d in the hashtable\n",pFind2->data);		
	else 
		printf("not find 4 in the hashtable\n");

	//ɾ������
	if(delete_HashTable(hashtable,1))
		printf("delete 1 success\n");
	else 
		printf("delete 1 fail");
	pNode pFind3 = search_HashTable(hashtable,1);
	if(pFind3)
		printf("find %d in the hashtable\n",pFind3->data);		
	else 
		printf("not find 1 in the hashtable,it has been deleted\n");

	//���ٹ�ϣ��
	destroy_HashTable(hashtable,len);
	return 0;
}
