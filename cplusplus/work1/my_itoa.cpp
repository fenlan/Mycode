/* Author: fenlan
 * Date: 2017.4.9
 * -------------------------
 *  convert int to string
 * -------------------------
 */

#include <iostream>
using namespace std;

const int MAX = 16;

char* my_itoa(int i, char b[]);

int main()
{
	char *p;
	int i = 43652653;
	char b[MAX] = "";

	p = b;
	p = my_itoa(i, b);
	cout << p << endl;

	return 0;    
}

char* my_itoa(int i, char b[])
{
	int j = 0;
	char int_string[MAX] = "";

	for (j = 0; i != 0; j++) {
		int_string[j] = i % 10 + '0';
		i /= 10;
	}
	
	for (int k = 0; k < j; k++)
		b[k] = int_string[j-k-1];
	return b;    
}
