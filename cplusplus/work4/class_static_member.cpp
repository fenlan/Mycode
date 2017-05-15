/* --------------------------------------------------
 * 	Author: fenlan
 * 	Date: 2017.5.14
 * 	Desc: I can not sure the program is correct
 * --------------------------------------------------
 *  	Define two classes, each with a static member,
 *  so that the construction of each static member
 *  involves a reference to the other.
 * --------------------------------------------------
 */


#include <iostream>
using namespace std;

class Obj1 {
	//static int default_value;
public:
	static int& default_value;
	Obj1(int value) {
		default_value = value;    
	}
	void print() {
		cout << default_value << endl;    
	}
};

class Obj2 {
	//static int default_value;
public:
	static int& default_value;
	Obj2(int value) {
		default_value = value;    
	}
	void print() {
		cout << default_value << endl;    
	}
};

int j = 0;
int& Obj1::default_value = j;
int& Obj2::default_value = Obj1::default_value;

int main()
{
	Obj1 a(1);
	Obj2 b(2);
	Obj1 c(3);
	Obj2 d(4);
	a.print();
	b.print();
	c.print();
	d.print();

	return 0;
}
