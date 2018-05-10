#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int W[100][100] = {0};

void FloydWarshall(int nodes) {
	for (int k = 1; k <= nodes; k++)
		for (int i = 1; i <= nodes; i++)
			for (int j = 1; j <= nodes; j++)
				W[i][j] = W[i][j] < (W[i][k] + W[k][j]) ? W[i][j] : (W[i][k] + W[k][j]);
}

int main()
{
	int nodes = 5;
	for (int i = 1; i <= nodes; i++)
		for (int j = 1; j <= nodes; j++)
			W[i][j] = INT_MAX / 2 - 100;

	W[1][1] = 0;	W[1][2] = -1;	W[1][3] = 3;
	W[2][2] = 0;	W[2][3] = 3;	W[2][4] = 2;	W[2][5] = 2;
	W[3][3] = 0;
	W[4][4] = 0;	W[4][2] = 1;	W[4][3] = 5;
	W[5][5] = 0;	W[5][4] = -3;

	FloydWarshall(nodes);

	cout.flags(ios::right);
	for (int i = 1; i <= nodes; i++) {
		for (int j = 1; j <= nodes; j++) {
			cout << setw(10) << W[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}