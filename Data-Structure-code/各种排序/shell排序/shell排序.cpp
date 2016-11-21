/*******************************
		   shell����
Author:��ͤ���� Date:2014-02-25
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>

/*
��һ����ʽ�Ĵ���
�Գ�Ϊlen���������һ������Ϊader�Ĳ�������
���㷨�ڲ��������㷨�ĵ�һ��ʵ����ʽ�Ͻ����޸ĵõ�
*/
void Shell_Insert1(int *arr,int len,int ader)
{
	int i,k;
	//ѭ����ader�������н��в����������
	for(k=0;k<ader;k++)
		for(i=ader+k;i<len;i+=ader)		//��һ�������н��в����������
		{	//����i��Ԫ�طֱ���ǰ���ÿ��ader��λ�õ�Ԫ�رȽϣ������ʵ���λ��
			if(arr[i]<arr[i-ader])
			{	//һֱ������бȽϣ�ֱ�����뵽�ʵ���λ��
				int key = arr[i];
				int count = 0;	//������¼key����ǰ��Ԫ�رȽ�ʱ�����ƶ��˼���ader����
				while(i>k && key<arr[i-ader])
				{
					arr[i] = arr[i-ader];
					arr[i-ader] = key;
					i -= ader;
					count++;
				}
				//�������������λ����һ��Ԫ�أ�ִ����һ�β�������
				//��Ϊ���滹Ҫִ��i+=ader����������ص�ԭλ�ü���
				i += count*ader;  
			} 
		}
}

/*
�ڶ�����ʽ�Ĵ���
�Գ�Ϊlen���������һ������Ϊader�Ĳ�������
���㷨�ڲ��������㷨�ĵڶ���ʵ����ʽ�Ͻ����޸ĵõ�
*/
void Shell_Insert2(int *arr,int len,int ader)
{
	int i,j,k;
	//ѭ����ader�������и��Խ��в�������
	for(k=0;k<ader;k++)
		for(i=ader+k;i<len;i+=ader)
			if(arr[i] < arr[i-ader])
			{
				int key = arr[i];
				for(j=i-ader;j>=k && arr[j]>key;j-=ader)
					arr[j+ader] = arr[j];
				arr[j+ader] = key;
			}
}

/*
�ڵڶ��ִ������ʽ�ϼ����������
������и��������еĲ�������
*/
void Shell_Insert2_1(int *arr,int len,int ader)
{
	int i,j;
	//��ader�����н�����в�������
	for(i=ader;i<len;i++)
		if(arr[i] < arr[i-ader])
		{
			int key = arr[i];
			for(j=i-ader;j>=0 && arr[j]>key;j-=ader)
				arr[j+ader] = arr[j];
			arr[j+ader] = key;
		}
}

/*
��������ʽ�Ĵ���
�Գ�Ϊlen���������һ������Ϊader�Ĳ�������
���㷨�ڲ��������㷨�ĵ�����ʵ����ʽ�Ͻ����޸ĵõ�
*/
void Shell_Insert3(int *arr,int len,int ader)
{
	int i,j,k;
	//ѭ����ader�������и��Խ��в�������
	for(k=0;k<ader;k++)
		for(i=ader+k;i<len;i+=ader)
			for(j=i-ader;j>=k && arr[j]>arr[j+ader];j-=ader)
			{
				//����Ԫ����ֵ
				arr[j]^=arr[j+ader];
				arr[j+ader]^=arr[j];
				arr[j]^=arr[j+ader];
			}
}

/*
�ڵ����ִ������ʽ�ϼ����������
������и��������еĲ�������
*/
void Shell_Insert3_1(int *arr,int len,int ader)
{
	int i,j;
	//�����ader�������н��в�������
		for(i=ader;i<len;i++)
			for(j=i-ader;j>=0 && arr[j]>arr[j+ader];j-=ader)
			{
				//����Ԫ����ֵ
				//����arr[j]������arr[j+1]��
				//��˿��԰�ȫ���øý�������
				arr[j]^=arr[j+ader];
				arr[j+ader]^=arr[j];
				arr[j]^=arr[j+ader];
			}
}

/*
shell������˳��Ϊ��С����,
arrΪҪ��������飬��Ϊlen��
addΪ�������飬��Ϊnum
*/
void Shell_Sort(int *arr,int len,int *add,int num)
{
	int i;
	//������nun�˲�ͬ�����Ĳ�������
	for(i=0;i<num;i++)
		Shell_Insert2_1(arr, len,add[i]);	//һ������Ϊadd[i]�Ĳ�������
}
 
int main()
{
	int len;
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&len);

	int i;
	int add[] = {3,2,1};  //��������
	int *arr = (int *)malloc(len*sizeof(int));
	printf("������������%d��Ԫ�أ�����Ϊ��������",len);
	for(i=0;i<len;i++)
		scanf("%d",arr+i);

	printf("shell������˳��");
	Shell_Sort(arr,len,add,3);
	for(i=0;i<len;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}