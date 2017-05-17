/* ------------------------------------------------------------
 *	Author: fenlan
 *	Date: 2017.5.17
 * ------------------------------------------------------------
 *	  Define two class with static member, so that each
 *	constructor of class involves a reference to other.
 *
 *	Father(Son* son, father_name);
 *	Son(Father* father, son_name);
 *
 *	Input:
 *		Father li(NULL, "li");
 *		Son wu(&li, "wu");
 *
 *		li.set(&wu);
 *	Output:
 *		li's son is wu
 *		wu's father is li
 * ------------------------------------------------------------
 */

#include <iostream>
#include <string>
using namespace std;

class Son;

class Father {
public:
	static Son* son;
	string father_name;
	Father(Son* s, string n) { son = s; father_name = n; };
	void set(Son* s) { son = s; };
	void print();
};

class Son {
public:
	static Father* father;
	string son_name;
	Son(Father* f, string n) { father = f; son_name = n; };
	void set(Father* f) { father = f; };
	void print();
};

void Father::print() {
	cout << father_name << "'s son is " << son->son_name << endl;
};
void Son::print() {
	cout << son_name << "'s father is " << father->father_name << endl;
};

Son* Father::son = NULL;
Father* Son::father = NULL;

int main()
{
	Father li(NULL, "li");
	Son wu(&li, "wu");

	li.set(&wu);
	li.print();
	wu.print();
	return 0;
}
