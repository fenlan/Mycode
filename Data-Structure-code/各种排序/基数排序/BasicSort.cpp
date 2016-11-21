/*******************************
		  ��������
Author:��ͤ���� Date:2014-03-03
Email:zyb_maodun@163.com
********************************/
#include<stdio.h>
#include<stdlib.h>

/*
�ڵ�һ�ּ��������ʵ����ʽ������Щ�޸�
����������˳��Ϊ��С����
arr[0...len-1]Ϊ�������飬�������������λ��
brr[0...len-1]Ϊ��������������
w[0...len-1]��������ȡ����ÿһλ�ϵ�������ÿ��Ԫ�ؾ���0-k�е�һ��ֵ
crr[0...k]����0...k��ÿ��ֵ���ֵĴ���
*/
void Count_Sort(int *arr,int *brr,int *w,int *crr,int len,int k)
{
	int i;
	//����crr��Ԫ����0
	for(i=0;i<=k;i++)
		crr[i] = 0;
	//ͳ������w��ÿ��Ԫ���ظ����ֵĸ���
	for(i=0;i<len;i++)
		crr[w[i]]++;
	//������w��С�ڵ���i��Ԫ�ظ���
	for(i=1;i<=k;i++)
		crr[i] += crr[i-1];
	//��arr�е�Ԫ�ط���brr�ж�Ӧ��λ����
	for(i=len-1;i>=0;i--)
	{
		brr[crr[w[i]]-1] = arr[i];
		//�������ͬ��Ԫ�أ��������һ��λ����
		crr[w[i]]--;
	}
	//�ٽ�brr�е�Ԫ�ظ��Ƹ�arr������arr��������
	for(i=0;i<len;i++)
	{
		arr[i] = brr[i];
	}
}

/*
����������˳��Ϊ��С����
���в���dΪԪ�ص�λ��
*/
void Basic_Sort(int *arr,int *brr,int *w,int *crr,int len,int k,int d)
{
	int i,j,val=1;
	//�ӵ�λ����λ���ν��м�������
	for(i=1;i<=d;i++)
	{	//w�б������arr��ÿ��Ԫ�ض�Ӧλ�ϵ���
		//��Χ��0-k֮��
		for(j=0;j<len;j++)
			w[j] = (arr[j]/val)%10;	
		//�Ե�ǰλ���м�������
		Count_Sort(arr,brr,w,crr,len,k);
		val *= 10;
	}
}

int main()
{
	int i; 
	//���������飬ÿ��Ԫ�ص�ÿһλ����0-7֮��
	int arr[] = {217,125,362,136,733,522};
	int brr[6];	//��������ÿ�μ��������Ľ��
	int w[6];	//ÿ��ѭ��ʱ�������λ�ϵ���
	int crr[8];	//ÿ��ѭ��ʱ�������λ�ϵ������ֵĴ���
	Basic_Sort(arr,brr,w,crr,6,7,3);
	printf("���������Ľ��Ϊ��");
	for(i=0;i<6;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}


