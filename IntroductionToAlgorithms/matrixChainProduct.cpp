#include <iostream>
#include <climits>
using namespace std;

int m[100][100] = {0};
int s[100][100] = {0};

void matrixChainOrder(int* p, int length) {
	int n = length - 1;
	for (int i = 1; i <= n; i++)		m[i][i] = 0;
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n-l+1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j-1; k++) {
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void printOptimalParens(int i, int j) {
	if (i == j)
		cout << "A" << i;

	else {
		cout << "(";
		printOptimalParens(i, s[i][j]);
		printOptimalParens(s[i][j]+1, j);
		cout << ")";
	}
}

int main()
{
	int p[5] = {3, 5, 2, 1, 10};
	int length = 5;

	matrixChainOrder(p, length);
	printOptimalParens(1, length-1);
	cout << endl;

	return 0;
}