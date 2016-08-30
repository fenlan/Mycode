# include <stdio.h>
# include <stdlib.h>

int main()
{
	int i = 0, j = 0, k = 0;
	int people_number = 0, loop_number = 0;
	
	int *peopleArray;

	//int peopleArray[100] = {0};    //test code
	printf("解决约瑟夫环问题\n");
	printf("Please input two integer number\n");
	printf("--the first is the people number--\n");
	printf("--the second id the loop number--\n");

	scanf("%d %d", &people_number, &loop_number);
	peopleArray = (int *)malloc(people_number * sizeof(int));
	for (j = 0;j<people_number;j++)
		*(peopleArray+j) = j + 1;
	for (j = 0;j<people_number;j++)         //test code
		printf("%d ", *(peopleArray+j));
	printf("\n");
	
	for (k = 0;k<people_number-1;k++)
	{
		for (j = 0;j<loop_number;)
		{
			if(i>=people_number)   i = 0; 
			if(*(peopleArray+i) != 0)
				j++;
			i++;
		}
		*(peopleArray+i-1) = 0;
		
		for(j = 0;j<people_number;j++)                 //test code
			printf("%d ",*(peopleArray+j));
		printf("\n");
	}
	
	for(j = 0;j<people_number;j++)
		if(*(peopleArray+j) != 0)   break;

	printf("%d\n", *(peopleArray+j));
	free(peopleArray);

	system("pause");
	return 0;
}