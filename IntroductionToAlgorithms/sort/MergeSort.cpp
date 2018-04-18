#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
const int MAX = 100;

void Merge(int* A, int startP, int middle, int endP) {
	int L[middle-startP+2] = {0};
	int R[endP-middle+1] = {0};

	for (int i = 0; i < middle-startP+1; i++)	L[i] = A[startP+i];
	for (int i = 0; i < endP-middle; i++)		R[i] = A[middle+i+1];

	L[middle-startP+1] = INT_MAX;
	R[endP-middle] = INT_MAX;

	int i = 0;
	int j = 0;
	int k = startP;
	while(k <= endP) {
		if (L[i] < R[j])		A[k++] = L[i++];
		else					A[k++] = R[j++];
	}
}

void MergeSort(int* A, int startP, int endP) {
	if (startP < endP) {
		int middle = (startP + endP) / 2;
		MergeSort(A, startP, middle);
		MergeSort(A, middle+1, endP);
		Merge(A, startP, middle, endP);
	}
}

int main()
{
	int i = 0;
	int A[MAX] = {0};
    FILE *file;
    file = fopen("../datafile.txt", "r");

    for (i = 0;;i++){
        if (fscanf(file,"%d", &A[i]) != 1) break;
        //printf("%d ", list[i].key);        //debug
    }
    fclose(file);
    MergeSort(A, 0, i - 1);
    for (int j = 0; j < i; j++) {
    	printf("%d ", A[j]);
    }
    printf("\n");

    return 0;
}