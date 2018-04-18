# include <stdio.h>
# include <stdlib.h>
const int MAX = 100;

void Exchange(int* A, int i, int j) {
	if (i == j) {
		return ;
	}
	else {
		int t = A[i];
		A[i] = A[j];
		A[j] = t;
	}
}

int partition(int* A, int startP, int endP) {
	int key = A[endP];
	int i = startP - 1;
	int j = startP;
	while(j < endP) {
		if (A[j] <= key) {
			Exchange(A, ++i, j++);
		}
		else 	j++;
	}
	Exchange(A, ++i, j);
	return i;
}

void QuickSort(int* A, int startP, int endP) {
	if (startP < endP) {
		int middle = partition(A, startP, endP);
		QuickSort(A, startP, middle-1);
		QuickSort(A, middle+1, endP);
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
    QuickSort(A, 0, i - 1);
    for (int j = 0; j < i; j++) {
    	printf("%d ", A[j]);
    }

    printf("\n");

    return 0;
}