/*******************************
		  ԭʼð������
Author:��ͤ���� Date:2014-02-26
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>
/*
ð��������˳��Ϊ��С����
*/
void Bubble_Sort(int *arr,int len)
{
	int i,j,exchange;
	for(i=0;i<len-1;i++)
		for(j=0;j<len-i-1;j++)
			if(arr[j] > arr[j+1])
			{
				exchange = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = exchange;
			}
}

int main()
{
	int num;
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&num);

	int i;
	int *arr = (int *)malloc(num*sizeof(int));
	printf("������������%d��Ԫ�أ�����Ϊ��������",num);
	for(i=0;i<num;i++)
		scanf("%d",arr+i);

	printf("ð��������˳��");
	Bubble_Sort(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}