#include <stdio.h>
#include <stdlib.h>
const int MAX = 100;

void InsertSort(int *A, int startP, int endP) {
	for (int i = startP+1; i <= endP; i++) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

int main() {
	int i = 0;
	int A[MAX] = {0};
    FILE *file;
    file = fopen("../datafile.txt", "r");

    for (i = 0;;i++){
        if (fscanf(file,"%d", &A[i]) != 1) break;
        //printf("%d ", list[i].key);        //debug
    }
    fclose(file);
    InsertSort(A, 0, i - 1);
    for (int j = 0; j < i; j++) {
    	printf("%d ", A[j]);
    }
    printf("\n");

    return 0;
}