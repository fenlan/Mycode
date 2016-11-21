#include<stdio.h>

/*
��һ����ʽʵ�ּ�������
����������˳��Ϊ��С����
arr[0...len-1]Ϊ�������飬ÿ��Ԫ�ؾ���0-k�е�һ��ֵ
brr[0...len-1]Ϊ�������������
crr[0...k]����0...k��ÿ��ֵ������arr�г��ֵĴ���
*/
void Count_Sort(int *arr,int *brr,int *crr,int len,int k)
{
	int i,j=0;
	//����crr��Ԫ����0
	for(i=0;i<=k;i++)
		crr[i] = 0;
	//ͳ������arr��ÿ��Ԫ���ظ����ֵĸ���
	for(i=0;i<len;i++)
		crr[arr[i]]++;
	//������arr��С�ڵ���i��Ԫ�ظ���
	for(i=1;i<=k;i++)
		crr[i] += crr[i-1];
	//��arr�е�Ԫ�ط���brr�ж�Ӧ��λ����
	for(i=len-1;i>=0;i--)
	{
		brr[crr[arr[i]]-1] = arr[i];
		//�������ͬ��Ԫ�أ��������һ��λ����
		crr[arr[i]]--;
	}
}

/*
�ڶ�����ʽʵ�ּ�������
����������˳��Ϊ��С����
arr[0...len-1]Ϊ�������飬ÿ��Ԫ�ؾ���0-k�е�һ��ֵ
crr[0...k]����0...k��ÿ��ֵ������arr�г��ֵĴ���
*/
void Count_Sort(int *arr,int *crr,int len,int k)
{
	int i,j=0;
	//����crr��Ԫ����0
	for(i=0;i<=k;i++)
		crr[i] = 0;
	//ͳ������arr��ÿ��Ԫ���ظ����ֵĸ���
	for(i=0;i<len;i++)
		crr[arr[i]]++;
	//����crr[i]�Ĵ�С����Ԫ��i����arr�ʵ���λ��
	for(i=0;i<=k;i++)
		while((crr[i]--)>0)
		{
			arr[j++] = i;
		}
}

int main()
{
	int i; 
	//���������飬ÿ��Ԫ�ؾ���0-8֮��
	int arr[] = {2,1,3,8,6,0};
	int brr[6];
	int crr[9];
	Count_Sort(arr,brr,crr,6,8);
	printf("���������Ľ��Ϊ��");
	for(i=0;i<6;i++)
		printf("%d ",brr[i]);
	printf("\n");
	return 0;
}