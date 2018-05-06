#include <iostream>
#include <climits>
using namespace std;

void ScheduleProblem(int* jobs, int length) {
	int minP = 0;
	int min = INT_MAX;
	
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++)
		if (jobs[j] < min) { 
			min = jobs[j];
			minP = j;
		}
		cout << "job" << minP << " ->";
		jobs[minP] = INT_MAX;
		min = INT_MAX;
	}
}

int main()
{
	int jobs[4] = {15, 8, 3, 10};
	ScheduleProblem(jobs, 4);

	return 0;
}