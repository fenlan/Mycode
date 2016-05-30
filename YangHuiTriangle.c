# include <stdio.h>
# include <stdlib.h>

int main ()
{
	int i = 0, j = 0;
	int number[15][15] = {0,0};
	int n;

	printf("Please input an integer no more than 14:\n");
	scanf("%d", &n);

	for (i=0;i<n;i++)
	{
		number[i][0] = 1;
		number[i][i] = 1;
	}

	for (i=2;i<n;i++)
		for (j=1;j<i;j++)
			number[i][j] = number[i-1][j-1] + number[i-1][j];

	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
			printf("  ");
		for (j=0;j<i+1;j++)
			printf("%3d ", number[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}