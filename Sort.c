# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int BubbleSort(int *,int );
/*��������������һ��ָ���ʾҪ��ð�ݷ����бȽϵ������һ��������ʾ�Ƚ����ĸ���
 *�������ã���ָ�봫��һ�����鵽�������д�С�������в��������бȽϵĴ���
 */
int SelectSort(int *,int );
/*��������������һ��ָ���ʾҪ�ñȽϷ����бȽϵ������һ��������ʾ�Ƚ����ĸ���
 *�������ã���ָ�봫��һ�����鵽�������д�С�������в��������бȽϵĴ���
 */
int main ()
{
	int rand_number[1000] = {0};
	int rand_number1[1000] = {0};      //ʹ��ð�ݷ�������
	int rand_number2[1000] = {0};      //ʹ�ñȽϷ�������
	int i = 0, times1 = 0, times2 = 0;     //times1��ʾð�ݷ��ıȽϴ�����times2��ʾ�ȽϷ��ıȽϴ���

	srand((int)time(0));
	for (i=0;i<1000;i++)
		rand_number[i] = rand() % 1000;        //����1000�������

	for (i=0;i<1000;i++)
	{
		rand_number1[i] = rand_number[i];
		rand_number2[i] = rand_number[i];
	}

	times1 = BubbleSort(rand_number1,1000);
	times2 = SelectSort(rand_number2,1000);

	printf("ð�ݷ���������times = %d\n", times1);
	for (i=0;i<1000;i++)     printf("%d ", rand_number1[i]);
	printf("\n");
	
	printf("�ȽϷ���������times = %d\n", times2);
	for (i=0;i<1000;i++)     printf("%d ", rand_number2[i]);
	printf("\n");

	system("pause");
	return 0;
}

int BubbleSort(int *rand_number,int n)
{
	int swaptag = 1;
	int * number;
	int i = 0, j = 0;
	int temp = 0;
	int times = 0;            //����Ƚϴ���
	number = rand_number;

	for (;swaptag && i<n-1;i++)
	{
		swaptag = 0;
		for (j=0;j<n-i-1;j++)
		{
			if (*(number+j)>*(number+j+1))
			{
				swaptag = 1;
				temp = *(number+j);    *(number+j) = *(number+j+1);   *(number+j+1) = temp;
			}
			times++;
		}
	}

	return times;
}

int SelectSort(int * rand_number,int n)
{
	int * number;
	int i = 0, j = 0, temp = 0;
	int t = 0, times = 0;
	number = rand_number;

	for (i=0;i<n-1;i++)
	{
		t = i;
		for (j=i+1;j<n;j++)
		{
			if (*(number+j)<*(number+t))    t = j;
			times++;
		}

		if (t!=i)
		{
			temp = *(number+i);
			*(number+i) = *(number+t);
			*(number+t) = temp;
		}
	}

	return times;
}