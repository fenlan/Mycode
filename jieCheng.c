//�������д�����
# include <stdio.h>
# include <stdlib.h>

int * JieCheng (int );
/*��������׳�
 *���Ϊ���飨ָ�룩
 *�ϵ�Ϊf[i] = 10,ʹ�øú���ʱ�ɶ���һ��ָ��ָ��ú�������ֵ��
 *�纯������ֵ��5370923 10�����10Ϊ�ϵ�
 *ע���ú������Ⱥܲ�д�����
 */
int main ()
{
	int number = 0;
	int * g;

	while (1)
	{
		printf("Please input a integer no more than 1000\n");
		scanf("%d", &number);

		printf("The result is:");
		g = JieCheng(number);

		for (;(*g)!=10;g++)      printf("%d",*g);
		printf("\n");
	}

	system("pause");
	return 0;
}

int * JieCheng (int number)
{
	int f[3000] = {0};       //������
	int i, j;

	f[0] = 1;
	for (i=1;i<=number;i++)            //������׳ˣ���1��������
	{
		int left = 0;

		for (j=0;j<3000;j++)           //�����ʾ����׳˴�����ÿһ����λ�����λ��f[0],ʮλ��f[1]
		{
			int sum = f[j] * i + left;        //�������ڲ�����
			f[j] = sum % 10;
			left = sum / 10;
		}
	}

	for (i=3000-1;;i--)    if (f[i]!=0)   break;
	for (j=0;j<i/2+1;j++)
	{
		int a = 0;
		a = f[j];               //�����鵹��
		f[j] = f[i-j];
		f[i-j] = a;
	}

	f[i+1] = 10;        //���öϵ㣬ʹ��ʱ�Դ���ֹ��� 
	return f;
}
