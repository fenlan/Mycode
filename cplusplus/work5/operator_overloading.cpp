/* ---------------------------------------------------
 * 	Author: fenlan
 * 	Date: 2017.5.22
 * ---------------------------------------------------
 * 	operator overloading
 * ---------------------------------------------------
 */


#include <iostream>
using namespace std;

struct X {
	int i;
	X(int i) {this->i = i;cout << "x_con" << endl;}
	//X(int i):i(i) {cout << "debug" << endl;}
	X operator+(int i) {
		cout << "x_plus" << "---->";
		return X(this->i + i);
	}
};

struct Y {
	int i;
	Y(X x) {this->i = x.i; cout << "y_con" << endl;}
	//Y(X x):i(x.i) {cout << "debug" << endl;}
	Y operator+(X x) {
		cout << "y_plus_x" << "---->";
		return Y(this->i + x.i);
	}
	operator int() {
		cout << "int_y" << "---->";
		return i;
	}
};

X operator*(X x, Y y) {
	cout << "operator *" << "---->";
	return X(x.i * y.i);
};
int f(X x) {
	return x.i;
};

X x = 1;
Y y = x;
int i = 2;

int main()
{
	cout << i + 10 << endl;
	//cout << y + 10 << endl; //invalid: ambiguity, could mean (int)y + 10 or y + x(10)
	//cout << y + 10*y << endl;//invalid: ambiguity, could mean y + (10*(int)y) or y + (x(10)*y)
	cout << (x + y + i).i << endl;
	cout << (x*x + i).i << endl;
	cout << f(7) << endl;
	//cout << f(y) << endl;//incalid: could not convert 'y' from 'Y' to 'X'
	cout << y + y << endl;
	cout << 106 + y << endl;
	return 0;
}
