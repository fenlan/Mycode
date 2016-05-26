//本程序有待完善
# include <stdio.h>
# include <stdlib.h>

int * JieCheng (int );
/*计算大数阶乘
 *输出为数组（指针）
 *断点为f[i] = 10,使用该函数时可定义一个指针指向该函数返回值，
 *如函数返回值：5370923 10，最后10为断点
 *注：该函数灵活度很差，有待改善
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
	int f[3000] = {0};       //待完善
	int i, j;

	f[0] = 1;
	for (i=1;i<=number;i++)            //迭代求阶乘，从1到所求数
	{
		int left = 0;

		for (j=0;j<3000;j++)           //数组表示所求阶乘大数的每一分数位，如个位是f[0],十位是f[1]
		{
			int sum = f[j] * i + left;        //具体求法在博客上
			f[j] = sum % 10;
			left = sum / 10;
		}
	}

	for (i=3000-1;;i--)    if (f[i]!=0)   break;
	for (j=0;j<i/2+1;j++)
	{
		int a = 0;
		a = f[j];               //将数组倒置
		f[j] = f[i-j];
		f[i-j] = a;
	}

	f[i+1] = 10;        //设置断点，使用时以此终止输出 
	return f;
}
