# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main ()
{
	char number1[1000] = "\0";        
	char number2[1000] = "\0";
	int num1[1000] = {0};
	int num2[1000] = {0};
	int num3[1000] = {0};
	int length1 = 0, length2 = 0, length = 0;
	int i = 0, j = 0;

	//for (i=0;i<1000;i++)  printf("num1 = %d num2 = %d\n",num1[i],num2[i]);
	
	printf("Please input two number:\n");
	scanf("%s %s", number1, number2);
	
	length1 = strlen(number1);
	length2 = strlen(number2);

	for (i=0;i<length1;i++)      num1[i] = number1[length1-i-1] - '0';
	for (i=0;i<length2;i++)      num2[i] = number2[length2-i-1] - '0';
	length = length1 < length2 ? length2 : length1;

	//printf("length = %d, length1 = %d, length2 = %d\n", length, length1, length2);//¡¾µ÷ÊÔÓï¾ä¡¿

	for (i=0;i<length;i++)    num3[i] = num1[i] + num2[i];
	for (i=0;i<length;i++)
	{
		if (num3[i]>=10)
		{
			num3[i+1] += 1;
			num3[i] = num3[i] % 10;
		}
	}

	printf("The result is :\n");
	if (num3[length]==0)   i = length - 1;
	else i = length;
	for (;i>=0;i--)    
		printf("%d", num3[i]);
		
	system("pause");
	return 0;
}