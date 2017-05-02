#include <iostream>
using namespace std;

const int MAX = 1000;

class Histogram {
	short int count[MAX] = {0};
	short int max_value, min_value;
public:
	Histogram(short int max, short int min) {
		max_value = max;
		min_value = min;
	};
	void Count(short int number) {
		//cout << max_value << " " << min_value;
		if (number > max_value || number < min_value) {
			cout << number <<" is out of range !" << endl;    
		}
		else {
			//cout << number << "->" << count[number] << " ";
			count[number]++;
		}
	};
	void print() {
		for (int i = min_value; i<=max_value; i++)
			if (count[i] != 0)
				cout << i << "->" << count[i] << " ";
		cout << endl;
	};
};

int main()
{
	Histogram his(10,1);
	his.Count(3);
	his.Count(4);
	his.Count(6);
	his.Count(3);
	his.Count(3);
	his.Count(13);

	his.print();

	return 0;    
}
