#include <iostream>
#include <string.h>
using namespace std;

class A {
	char name[5];
public:
	A(char* s) {
		cout << "Constructor-----" << s << endl;
		strcpy(name, s);
	}
	~A() {
		cout << "Descontructor----" << name << endl;
	}
};

A a("a");

int main()
{
	int c = 9;
	static A b("b");
	return 0;
}

static A m("m");
