/* ------------------------------------------------------------
 *	Author: fenlan
 *	Date: 2017.6.4
 * ------------------------------------------------------------
 *	Define
 *      class Base {
 *      public:
 *          virtual void iam() { cout << "Base\n"; }
 *      };
 *
 *	Derive two classes from Base, and for each define iam() to
 *  write out the name of the class. Create objects of these
 *  classes and call iam() for them. Assign pointers to objects
 *  of the derived classes to Base* pointers and call iam()
 *  through those pointers.
 * ------------------------------------------------------------
 *	Output:
 *      Base
 *      Derived1
 *      Derived2
 *      Base
 *      Derived1
 *      Derived2
 * ------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class Base {
public:
    virtual void iam() { cout << "Base" << endl; }
};

class Derived1 : public Base {
public:
    void iam() { cout << "Derived1" << endl; }
};

class Derived2 : public Base {
public:
    void iam() { cout << "Derived2" << endl; }
};

int main()
{
    Base base;
    Derived1 d1;
    Derived2 d2;

    base.iam();
    d1.iam();
    d2.iam();

    Base* p;
    Base* q;
    Base* r;
    p = &base;      p->iam();
    q = &d1;        q->iam();
    r = &d2;        r->iam();

    return 0;
}
