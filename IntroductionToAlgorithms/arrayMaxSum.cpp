#include <iostream>
using namespace std;

int main()
{
	int A[6] = {-2, 11, -4, 13, -5, -2};
	int max = A[0], val = 0;

	for (int i = 0; i < 6; i++) {
		if (val >= 0)	val += A[i];
		else			val = A[i];
		if (max < val)	max = val;
	}
	cout << max << endl;

	return 0;
}