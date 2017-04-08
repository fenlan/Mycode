/* Author: fenlan
 * Date: 2017.4.8
 * Describe: Read a sequence of possibly whitespace-separated(name, value)
 * pairs, where the name is a single whitespace-separated word and the
 * value is an integer or a floating-point value. Compute and print the sum
 * and mean for each name and the sum and mean for all names.
 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef vector<double> val;
typedef map<string, val> MAP;

int main() {
	string name;
	int i = 0;
	double value = 0;
	MAP my_map;
	double sum = 0, mean = 0;

	cout << "Enter <name, value> pair, end with 'end' ";

	while (true) {
		cin >> name;
		if (name == "end")     break;
		cin >> value;

		my_map[name].push_back(value);
		sum += value;
		i++;
	}
	
	map<string, val>::iterator Map_Itr;
	for (Map_Itr = my_map.begin(); Map_Itr != my_map.end(); Map_Itr++) {
		int i = 0;
		double each_sum = 0, each_mean = 0;

		cout << "name: " << Map_Itr->first;
		
		for (i =  0; i < (Map_Itr->second).size(); i++)
			each_sum += Map_Itr->second[i];

		each_mean = each_sum / i;
		cout << "  sum = " << each_sum << " mean = " << each_mean << endl;
	}

	mean = sum / i;
	cout << "all sum = " << sum << " all mean = " << mean << endl;

    return 0;
}
