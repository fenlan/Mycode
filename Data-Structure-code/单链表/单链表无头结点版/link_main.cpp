#include "sll_node.h"

Node *root = NULL;

int main()
{ 

	/*�������ݣ������ڴ棬������ԭʼ���к�����������*/
	input_data(&root);
	if(root== NULL)
		printf("No data entered.");
	else
	{
		printf("Here is the list:\n");
		show(root);
		printf("\nThe sorted list is:\n");
		sort(root);
		show(root);
		printf("\nTotal itms of the list is:\n %d",count(root));
	}


	/*������Ҫ��ӵ�����*/
	while(getchar() != '\n')
		continue;                        //������ز����٣���Ҫ�Ƿ�ֹscanf�����һ�ζ�ȡ��������ĸ����Զ����Խ����
	int new_value;
	printf("\nNow enter the new value:\n");
	scanf("%d",&new_value);
	while(getchar( ) != '\n')
		continue;
	

	/*������ӵ������Ƿ����������Ѿ����ڣ������ڣ���ʾ�������룬ֱ��������Ϊֹ*/
	while(!check(root,new_value) )
	{
		printf("Existed in the list ,please input another data:");
		scanf("%d",&new_value);
			while(getchar() != '\n')
				continue;
	}


	/*������ӵ����ݼ����½��Ľڵ㣬�������ڴ棬����������ʾ����������*/
	if(sell_insert(&root,new_value))
	{
		printf("\nNow the list is:\n");
		show(root);
		printf("\nNow total itms of the list is:\n %d",count(root));
	}
	else 
		printf("insert error\n");
	printf("\n");


	/*�����ɾ��������*/
	int delete_value;
	printf("\nNow enter the deleted value:\n");
	scanf("%d",&delete_value);
	while(getchar() != '\n')
		continue;


	/*�����ɾ�������ݲ��������У���ʾ�������룬֪������Ϊֹ*/
	while(check(root,delete_value) )
	{
		printf("Not exist in the list ,please input a data in the list:");
		scanf("%d",&delete_value);
			while(getchar() != '\n')
				continue;
	}


	/*����ɾ�����������ڵĽڵ���ռ�õ��ڴ��ͷŵ�����ɾ����������������������ʾɾ�����ݺ������*/
	delete_data(&root,delete_value);
	printf("\nNow the list is:\n");
	show(root);
	printf("\nNow total itms of the list is:\n %d",count(root));
	printf("\n");


	/*�ͷ�������ռ�õ��ڴ�*/
    free_list(&root);

	return 0;
}
