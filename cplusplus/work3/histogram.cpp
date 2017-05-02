/* Author: fenlan
 * Date: 2017.5.2
 * -----------------------------------------------
 *  	define a class Histogram to get the data
 *  statistical
 * -----------------------------------------------
 * input:
 * 		3 4 5 3 6 3 6 9
 * output:
 * 		3->3 4->1 5->1 6->2 9->1
 * -----------------------------------------------
 */

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
