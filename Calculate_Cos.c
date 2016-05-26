# include <stdio.h>
# include <stdlib.h>
# include <math.h>

double Cos(double );
double Jie_Cheng(int );
int main ()
{
	double the_result1 = 0;          //该变量输出由math.h中cos函数计算的值
	double the_result = 0;           //该变量输出自己计算的cos值
	double the_input_number = 0;     //储存用户输入的待测值

	printf("----The programming is to calculate cos----\n");
	while (1)
	{
		printf("\nPlease input a number :");
		scanf("%lf", &the_input_number);

		the_result = Cos(the_input_number);
		the_result1 = cos(the_input_number);
		printf("The test result is : %.6lf\nThe real result is : %.6lf\n",the_result, the_result1);
	}

	system("pause");
	return 0;
}

double Cos(double the_input_number)
{
	int i = 1;
	double the_number_sign = 1;
	double the_number_pow = 1;
	double cosx = 1;

	for (i=1;;i++)
	{
		the_number_sign *= -1;
		the_number_pow *= (the_input_number * the_input_number);
		if (the_number_pow/Jie_Cheng(2*i) < 0.000001)   break;
		cosx += the_number_sign * the_number_pow / Jie_Cheng(2*i);
	}
	return cosx;
}

double Jie_Cheng(int i)
{
	double the_output_number = 1;
	int j = 1;

	for (j=1;j<=i;j++)    the_output_number *= j;
	return the_output_number;
}