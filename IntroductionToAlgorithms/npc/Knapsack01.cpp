#include <iostream>
using namespace std;

int Knapsack01(int num, int capacity, int* weight, int* value) {
	int m[num+1][capacity+1] = {0};

	for (int w = 0; w <= capacity; w++)
		m[0][w] = 0;
	for (int i = 1; i <= num; i++)
		m[i][0] = 0;

	for (int i = 1; i <= num; i++) {
		for (int w = 1; w <= capacity; w++) {
			if (weight[i-1] > w)		m[i][w] = m[i-1][w];
			else
				m[i][w] = (m[i-1][w]) > (value[i-1] + m[i-1][w-weight[i-1]]) 
					? (m[i-1][w]) : (value[i-1] + m[i-1][w-weight[i-1]]);
		}
	}
	return m[num][capacity];
}

int main()
{
	int num = 5, capacity = 100;
	int weight[5] = {10, 20, 30, 40, 50};
	int value[5] = {20, 30, 65, 40, 60};

	cout << Knapsack01(num, capacity, weight, value) << endl;

	return 0;
}