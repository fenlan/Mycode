/*******************************
		  ֱ�Ӳ�������
Author:��ͤ���� Date:2014-02-25
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>
/*
��һ�ִ�����ʽ
����������˳��Ϊ��С����
*/
void Insert_Sort1(int *arr,int len)
{
	int i;
	//�ӵ�1��Ԫ�ؿ�ʼѭ��ִ�в�������
	for(i=1;i<len;i++)	
	{	//����i��Ԫ�طֱ���ǰ���Ԫ�رȽϣ������ʵ���λ��
		int key = arr[i];
		if(key<arr[i-1])
		{	//һֱ������бȽϣ�ֱ�����뵽�ʵ���λ��
			int count = 0;	//������¼key����ǰ��Ԫ��ʱ�����ƶ���λ��
			while(i>0 && key<arr[i-1])
			{
				arr[i] = arr[i-1];
				arr[i-1] = key;
				i--;
				count++;
			}
			//�������������λ����һ��Ԫ�أ�
			//��Ϊ���滹Ҫִ��i++���������ﲻ�ټ�1
			i += count;  
		} 
	}
}

/*
�ڶ��ִ�����ʽ
����������˳��Ϊ��С����
*/
void Insert_Sort2(int *arr,int len)
{
	int i,j;
	for(i=1;i<len;i++)
		if(arr[i] < arr[i-1])
		{	//��ǰ����Ƚϣ�ֱ����Ҫ����ĵط�
			int key = arr[i];
			for(j=i-1;j>=0 && arr[j]>key;j--)
				arr[j+1] = arr[j];
			arr[j+1] = key;	   //����key
		}
}

/*
�����ִ�����ʽ
����������˳��Ϊ��С����
*/
void Insert_Sort3(int *arr,int len)
{
	int i,j;
	for(i=1;i<len;i++)
		for(j=i-1;j>=0 && arr[j]>arr[j+1];j--)
		{
			//����Ԫ����ֵ
			//����arr[j]������arr[j+1]��
			//��˿��԰�ȫ���øý�������
			arr[j]^=arr[j+1];
			arr[j+1]^=arr[j];
			arr[j]^=arr[j+1];
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
//	Insert_Sort1(arr,num);
//	Insert_Sort2(arr,num);
	Insert_Sort3(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);
	printf("\n");

	free(arr);
	arr = 0;
	return 0;
}