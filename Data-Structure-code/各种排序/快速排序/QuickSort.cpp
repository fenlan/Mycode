/*******************************
		   ��������
Author:��ͤ���� Date:2014-02-28
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Quick_Sort(int *,int,int);
int findPoss(int *,int,int);
int Patrition(int *,int,int);
int Random_Partition(int *,int,int);
void swap(int *,int *);

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
	Quick_Sort(arr,0,num-1);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}

/*
������������ͨ���ݹ�ʵ��
*/
void Quick_Sort(int *a,int low,int high)
{
	int pos;

	if(low < high)
	{
	   pos = Random_Partition(a,low,high);
	   Quick_Sort(a,low,pos-1);		//�������������
	   Quick_Sort(a,pos+1,high);	//�ұ����������� 
	}
}

/*
�ú������طָ����ֵ���ڵ�λ��,aΪ������������׵�ַ��
low�տ�ʼ��ʾ����Χ�ڵĵ�һ��Ԫ�ص�λ�ã��������ƶ���
high�տ�ʼ��ʾ����Χ�ڵ����һ��λ�ã��������ƶ�
*/
int findPoss(int *a,int low,int high)
{
	if(a==NULL || low>high)
		return -1;

	int val = a[low];
	while(low < high)
	{
	   while(low<high && a[high]>=val)
	      high--;
	   a[low] = a[high];

	   while(low<high && a[low]<=val)
	      low++;
	   a[high] = a[low];	     
	}

	//����low=high
	a[low] = val;
	return low;
}

/*
�㷨���۰��������
*/
int Partition(int *a,int low ,int high)
{
	if(a==NULL || low>high)
		return -1;

	int small = low-1;
	int j;
	for(j=low;j<high;j++)
	{
		if(a[j]<a[high])
		{
			small++;
			if(small != j)
				swap(&a[small],&a[j]);
		}
	}
	small++;
	swap(&a[small],&a[high]);
	return small;
}

/*
���ѡȡ����Ԫ��
*/
int Random_Partition(int *A,int low,int high)
{
	//�����������
	srand((unsigned)time(0));
	int index = low + rand()%(high-low+1);
	swap(&A[index],&A[high]);
	return Partition(A,low,high);
}


void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}