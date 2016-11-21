/*******************************
		    �鲢����
Author:��ͤ���� Date:2014-02-26
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>

/*
�������arr[start...mid]�������arr[mid+1...end]�鲢Ϊ�����arr[start...end]
*/
void Merge(int *arr,int start,int mid,int end)
{
	int i = start;
	int j = mid+1;
	int k = 0;
	//brrΪ�������飬
	int *brr = (int *)malloc((end-start+1)*sizeof(int));

	//�Ƚ��������������е�Ԫ�أ�����С��Ԫ�ز��뵽brr��
	while(i<=mid && j<=end)
	{	
		if(arr[i]<=arr[j])
			brr[k++] = arr[i++];
		else
			brr[k++] = arr[j++];
	}

	//��arr������ʣ���Ԫ�ظ��Ƶ�brr��
	//���������ֻ����ִ������һ��
	while(i<=mid)
		brr[k++] = arr[i++];
	while(j<=end)
		brr[k++] = arr[j++];

	//��brr�е�Ԫ�ظ��Ƶ�arr�У�ʹarr[start...end]����
	for(i=0;i<k;i++)
		arr[i+start] = brr[i];

	//�ͷ�brr��ռ���ڴ棬��������Ϊ��
	free(brr);    
	brr = 0;
}

/*
��arr[start...end]�ڵ�Ԫ�ؽ��й鲢����
�鲢������˳��Ϊ��С����
*/
void MSort(int *arr,int start,int end)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		MSort(arr,start,mid);		//��ߵݹ�����
		MSort(arr,mid+1,end);		//�ұߵݹ�����
		Merge(arr,start,mid,end);	//�������й鲢
	}
}
/*
���������㷨��װ����
*/
void Merge_Sort(int *arr,int len)
{
	MSort(arr,0,len-1);
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

	printf("�鲢������˳��");
	Merge_Sort(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}