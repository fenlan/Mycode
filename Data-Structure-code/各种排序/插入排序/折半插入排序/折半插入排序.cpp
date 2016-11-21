/*******************************
		  �۰��������
Author:��ͤ���� Date:2014-02-25
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>
/*
����������˳��Ϊ��С����
*/
void BInsert_Sort(int *arr,int len)
{
	int i;
	//�ӵ�1��Ԫ�ؿ�ʼѭ��ִ�в�������
	for(i=1;i<len;i++)	
	{	
		int low =0;
		int high = i-1;
		int key = arr[i];
		//ѭ����Ҫ�����������֮��
		while(low<=high)
		{
			int mid = (low+high)/2;	
			if(key<arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		//ѭ��������low=high+1������lowλ�ü�ΪkeyҪ�����λ��

		//��low��i��Ԫ�����κ���һλ
		int j;
		for(j=i;j>low;j--)
			arr[j] = arr[j-1];
		//��key���뵽lowλ�ô�
		arr[low] = key;
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
	BInsert_Sort(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}