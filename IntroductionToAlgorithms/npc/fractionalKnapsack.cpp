#include <iostream>
using namespace std;

int fractionalKnapsack(int num, int capacity, int* weight, int* value) {
	double max = 0.0;
	int maxP = 0;
	int sumV = 0;
	double fractional[num] = {0.0};
	for (int i = 0; i < num; i++)
		fractional[i] = value[i] / (double)weight[i];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			if (fractional[j] > max) { 
				max = fractional[j];
				maxP = j;
			}
		if (capacity >= weight[maxP]) { 
			capacity -= weight[maxP]; 
			sumV += value[maxP];
		}
		else { 
			sumV += capacity * fractional[maxP];
			break;
		}
		fractional[maxP] = -1;
		max = 0;
	}
	return sumV;
}

int main()
{
	int num = 5, capacity = 100;
	int weight[5] = {10, 20, 30, 40, 50};
	int value[5] = {20, 30, 65, 40, 60};

	cout << fractionalKnapsack(num, capacity, weight, value) << endl;

	return 0;
}