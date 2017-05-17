/*
 ****************************************************************
	Define two class with static member, so that each constructor
  of class involves a reference to other.
 *****************************************************************
 */


#include <iostream>
using namespace std;
class son;
class father
{
public:
	char *Fname;
	static son * s;
	father(son *son, char* name) { s = son; Fname = name; }
	void change(son *st) { s = st; }
	void print();
};
class son
{
public:
	char *Sname;
	static father *f;
	son(father *far, char *name) { f = far; Sname = name; }
	void print();
};
void father::print()
{
	cout << "the father's name:" << Fname << endl
		<< "his son's name:" << s->Sname << endl;
}
void son::print()
{
	cout << "the son's name:" << Sname << endl
		<< "his father's name:" << f->Fname << endl;
}
son* father::s = NULL;
father* son::f = NULL;

void main()
{
	char name1[10], name2[10];
	cout << "input father's name:";
	cin >> name1;
	father f(NULL, name1);
	cout << "input son's name:";
	cin >> name2;
	son s(&f, name2);
	f.change(&s);
	s.print();
	f.print();
}
