#ifndef _MYSTRING_
#define _MYSTRING_
#include <istream>
#include <ostream>
#include <cstring>
using namespace std;

class String {
    struct Srep;                        // representation
    Srep* rep;
public:
    String();                           // x = ""
    String(const char*);                // x = "abc"
    String(const String&);              // x = other_string
    String& operator=(const char*);
    String& operator=(const String&);
    ~String();

    class Cref;                         // reference to char
    class Range {};                     // for exceptions

    void check(int i) const;
    char read(int i) const;
    void write(int i, char c);


    //Cref operator[] (int i);
    char operator[] (int i) const;

    int size() const;

    String& operator+=(const String&);
    String& operator+=(const char*);

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);

    friend bool operator==(const String& x, const char* s);
    friend bool operator==(const String& x, const String& y);
    friend bool operator!=(const String& x, const char* s);
    friend bool operator!=(const String& x, const String& y);
};

String operator+(const String&, const String&);
String operator+(const String&, const char*);

#endif
