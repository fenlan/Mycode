#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DSIZE 100

void sortInteger(int *, int *);

int main()
{
	int number = 5;
	int *ptr;
	ptr = (int *)malloc(DSIZE * sizeof(int));
	if (!ptr)
	{
		exit(0);
	}

	int i = 0;
	srand((int)time(0));
	for (i; i < number; ++i)
	{
		*(ptr+i) = rand();
	}

	*(ptr+i) = rand();
	sortInteger(ptr,&i);

	for (int i = 0; i <= number; ++i)           //test code
	{
		printf("%d\n", *(ptr+i));
	}

	free(ptr);
	return 0;
}


void sortInteger(int *sortArray, int *sizeofArray)
{
	int m = 0, n = 0;
	for(m = *sizeofArray-1;m>=0;m--)
	{
		for(n = 0;n<m;n++)
		{
			if(*(sortArray+n)>*(sortArray+n+1))
			{
				int t;
				t = *(sortArray+n);
				*(sortArray+n) = *(sortArray+n+1);
				*(sortArray+n+1) = t;
			}
		}
	}
}





