#include <iostream>
#include <fstream>
using namespace std;

int b[100][100] = {0};
int c[100][100] = {0};

void LCSLength(char* x, int length1, char*y, int length2) {
	for (int i = 1; i <= length1; i++)	c[i][0] = 0;
	for (int j = 0; j <= length2; j++)	c[0][j] = 0;

	for (int i = 1; i <= length1; i++) {
		for (int j = 1; j <= length2; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 0;
			} 
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 1;
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = -1;
			}
		}
	}
}

void printLCS(char* x, int i, int j) {
	if (i == 0 || j == 0)	return ;
	if (b[i][j] == 0) {
		printLCS(x, i-1, j-1);
		cout << x[i-1];
	}
	else if (b[i][j] == 1) {
		printLCS(x, i-1, j);
	}
	else		printLCS(x, i, j-1);
}

int main()
{
	char x[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
	char y[6] = {'B', 'D', 'C', 'A', 'B', 'A'};
	int length1 = 7;
	int length2 = 6;
	LCSLength(x, length1, y, length2);
	printLCS(x, length1, length2);
	cout << endl;

	return 0;
}