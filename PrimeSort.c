# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int BubbleSort(int *,int );
/*函数参数：传递一个指针表示要用冒泡法进行比较的数组和一个整数表示比较数的个数
 *函数作用：用指针传递一个数组到函数进行从小到大排列并返回其中比较的次数
 */
int SelectSort(int *,int );
/*函数参数：传递一个指针表示要用比较法进行比较的数组和一个整数表示比较数的个数
 *函数作用：用指针传递一个数组到函数进行从小到大排列并返回其中比较的次数
 */
int main ()
{
	int rand_number[1000] = {0};
	int rand_number1[1000] = {0};      //使用冒泡法的数组
	int rand_number2[1000] = {0};      //使用比较法的数组
	int i = 0, times1 = 0, times2 = 0;     //times1表示冒泡法的比较次数，times2表示比较法的比较次数

	srand((int)time(0));
	for (i=0;i<1000;i++)
		rand_number[i] = rand() % 1000;        //产生1000个随机数

	for (i=0;i<1000;i++)
	{
		rand_number1[i] = rand_number[i];
		rand_number2[i] = rand_number[i];
	}

	times1 = BubbleSort(rand_number1,1000);
	times2 = SelectSort(rand_number2,1000);

	printf("冒泡法计算结果：times = %d\n", times1);
	for (i=0;i<1000;i++)     printf("%d ", rand_number1[i]);
	printf("\n");
	
	printf("比较法计算结果：times = %d\n", times2);
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
	int times = 0;            //计算比较次数
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