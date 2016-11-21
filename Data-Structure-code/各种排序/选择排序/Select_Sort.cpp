/*******************************
		   ѡ������
Author:��ͤ���� Date:2014-02-26
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>
/*
��һ����ʽ��ѡ������
ѡ��������˳��Ϊ��С����
*/
void Select_Sort1(int *arr,int len)
{
	int i,j;
	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			if(arr[i] > arr[j])
			{
				int exchange = arr[i];
				arr[i] = arr[j];
				arr[j] = exchange;
			}
}

/*
�ڶ�����ʽ��ѡ�����򣬼�����Ԫ�ػ����Ĳ���
ѡ��������˳��Ϊ��С����
*/
void Select_Sort2(int *arr,int len)
{
	int i,j,min;
	for(i=0;i<len;i++)
	{
		min = i;	//������¼ÿһ�˱Ƚϵ���Сֵ��λ��
		for(j=i+1;j<len;j++)
			if(arr[min] > arr[j])
				min = j;	 //����¼��Сֵ��λ��
		//�����Сֵ��λ�÷����˱仯��
		//�����ִ��һ��Ԫ�ػ����Ĳ���
		if(min != i)
		{
			int exchange = arr[i];
			arr[i] = arr[min];
			arr[min] = exchange;
		}
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

	printf("����������˳��");
	Select_Sort2(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}