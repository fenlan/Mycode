#include <iostream>
#include <string>
using namespace std;

const int QUEUEMAX = 100;

void maxHeapify(int* A, int i) {
	int largest = 0;
	int left = 2*i;
	int right = 2*i+1;
	if (left <= A[0] && A[left] > A[i])	largest = left;		// A[0] represents heapSize
	else									largest = i;
	if (right <= A[0] && A[right] > A[i])	largest = right;
	if (largest != i) {
		int t = A[i];
		A[i] = A[largest];
		A[largest] = t;
		maxHeapify(A, largest);
	}
}

void insert(int* A, int elem) {
	int i = ++A[0];
	A[i] = elem;
	while (true) {
		int parent = i / 2;
		if (parent == 0)		break;
		if (A[i] <= A[parent])	break;
		else {
			int t = A[i];
			A[i] = A[parent];
			A[parent] = t;
			i = parent;
		}
	}
}

int pop(int* A) {
	if (A[0] == 0)	return -1;
	else {
		// remove the top of heap, then set the last one to the top
		int result = A[1];
		A[1] = A[A[0]--];
		maxHeapify(A, 1);
		return result;
	}
}

int main()
{
	int A[QUEUEMAX] = {0};
	while (true) {
		cout << "Please insert or pop a elem" << endl;
		string str;
		cin >> str;
		if (str == "insert") {
			cout << "Please insert a elem" << endl;
			int elem = 0;
			cin >> elem;
			insert(A, elem);
			cout << "Insert Successed! " << A[1] << endl;
		}
		else if (str == "pop") {
			int result = pop(A);
			if (result == -1)	cout << "Queue is empty!" << endl;
			else				cout << result << endl;
		}
		else if (str == "exit") 	break;
	}

	return 0;
}