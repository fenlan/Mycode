/* ------------------------------------------------------------
 *	Author: fenlan
 *	Date: 2017.6.4
 * ------------------------------------------------------------
 *      Given classes Circle, Square, and Triangle derived from
 *  a class Shape, define a function intersect() that takes two
 *  Shape* agruments and calls suitable functions to determine
 *  if the two shapes overlap. It will be necessary to add
 *  suitable (virtual) functions to the classes to achieve this.
 *  Don't bother to write the code that checks for overlap; just
 *  make sure the right functions are called. This is commonly
 *  referred to as double dispatch or a multi-method.
 * ------------------------------------------------------------
 */

#include <iostream>
using namespace std;

class Circle;
class Square;
class Triangle;

class Shape {
public:
   virtual bool intersect(Shape* s) = 0;
   virtual bool intersect(Circle& s) = 0;
   virtual bool intersect(Square& s) = 0;
   virtual bool intersect(Triangle& s) = 0;
};

class Circle : public Shape {
public:
   bool intersect(Shape* s) { return s->intersect(*this); }

   bool intersect(Circle& s)
   {
       cout << "Checking if Circle intersects with Circle" << endl;
       return true;
   }

   bool intersect(Square& s)
   {
       cout << "Checking if Circle intersects with Square" << endl;
       return false;
   }

   bool intersect(Triangle& t)
   {
       cout << "Checking if Circle intersects with Triangle" << endl;
       return false;
   }
};

class Square : public Shape {
public:
   bool intersect(Shape* s) { return s->intersect(*this); }

   bool intersect(Circle& s) { return s.intersect(*this); }

   bool intersect(Square& s)
   {
       cout << "Checking if Square intersects with Square" << endl;
       return true;
   }

   bool intersect(Triangle& s)
   {
       cout << "Checking if Square intersects with Triangle" << endl;
       return false;
   }
};

class Triangle : public Shape {
public:
   bool intersect(Shape* s) { return s->intersect(*this); }

   bool intersect(Circle& s) { return s.intersect(*this); }

   bool intersect(Square& s) { return s.intersect(*this); }

   bool intersect(Triangle& s)
   {
       cout << "Checking if Triangle intersects with Triangle" << endl;
       return true;
   }
};

bool intersect(Shape* s1, Shape* s2)
{
   return s1->intersect(s2);
}

int main()
{
    Circle circle;
    Square square;
    Triangle triangle;

    cout << intersect(&circle, &square) << endl;
    cout << intersect(&circle, &triangle) << endl;
    cout << intersect(&square, &circle) << endl;
    cout << intersect(&square, &triangle) << endl;
    cout << intersect(&triangle, &circle) << endl;
    cout << intersect(&triangle, &square) << endl;
    cout << intersect(&circle, &circle) << endl;
    cout << intersect(&square, &square) << endl;
    cout << intersect(&triangle, &triangle) << endl;

    return 0;
}
