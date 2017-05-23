#include "mystring.hpp"
#include <iostream>
using namespace std;

struct String::Srep {
    char* s;            // pointer to elements
    int sz;             // number of characters
    int n;              // reference count

    Srep(int nsz, const char* p) {
        n = 1;
        sz = nsz;
        s = new char[sz+1];         // add space for terminator
        strcpy(s,p);
    }

    ~Srep() { delete[] s; }

    Srep* get_own_copy() {            // clone if necessary
        if(n==1) return this;
        n--;
        return new Srep(sz, s);
    }

    void assign(int nsz, const char* p) {
        if(sz != nsz) {
            delete[] s;
            sz = nsz;
            s = new char[sz+1];
        }
        strcpy(s,p);
    }

private:                // prevent copying
    Srep(const Srep&);
    Srep& operator=(const Srep&);
};

class String::Cref {        // reference to s[i]
    friend class String;
    String& s;
    int i;
    Cref(String& ss, int ii) : s(ss), i(ii) {}
public:
    operator char() const { return s.read(i); }     // yield value
    void operator=(char c) { s.write(i, c); }       // change value
};

String::String() {          // the empty string is the default value
    rep = new Srep(0, "");
}

String::String(const char* s) {
    rep = new Srep(strlen(s), s);
}

String::String(const String& s) {       // copy constructor
    s.rep->n++;
    rep = s.rep;                // share representation
}

String& String::operator=(const char* s) {
    if(rep->n == 1)             // recyle Srep
        rep->assign(strlen(s), s);
    else {                      // use new Srep
        rep->n--;
        rep = new Srep(strlen(s), s);
    }
    return *this;
}

String& String::operator=(const String& s) {        // copy assignment
    s.rep->n++;                 // protects against "st = st"
    if(--(rep->n) == 0) delete rep;
    rep = s.rep;                // share representation
    return *this;
}

String::~String() {           // need your help, I have a little difficultice
    if(--(rep->n) == 0) delete rep;
    cout << rep->n <<" desconstructor\n";
}

void String::check(int i) const { if (i<0 || rep->sz<=i) throw Range(); }
char String::read(int i) const { return rep->s[i]; }
void String::write(int i, char c) { rep=rep->get_own_copy(); rep->s[i]=c; }

//String::Cref String::operator[](int i) { check(i); return Cref(*this, i); }
char String::operator[](int i) const { check(i); return rep->s[i]; }
int String::size() const { return rep->sz; }

String& String::operator+=(const String& x) {
    return *this += x.rep->s;
}

String& String::operator+=(const char* x) {
    int sz = rep->sz+strlen(x);
    char* s = new char[sz+1];
    strcpy(s, rep->s);
    strcat(s, x);
    rep->assign(sz, s);
    delete s;
    return *this;
}

ostream& operator<<(ostream& o, const String& x) {
    o << x.rep->s;
    return o;
}

const int INPUT_BUF = 255;
istream& operator>>(istream& i, String& x) {
    // I purposely avoid using std::string here. Using string
    // would have made this code much more clear. Just another
    // example of why you shouldn't avoid STL.

    char* s = new char[INPUT_BUF+1];
    int n = 0;
    int sz = INPUT_BUF;
    char ch;

    while(i && i.get(ch) && !isspace(ch))
    {
        s[n++] = ch;
        if(n > sz)
        {
            s[n]=0;
            char* s2 = new char[sz * 2 + 1];
            strcpy(s2,s);
            delete s;
            s = s2;
            sz *= 2;
        }
    }
    s[n]=0;

    x = String(s);
    delete s;
    return i;
}

bool operator==(const String& x, const char* s)
    { return strcmp(x.rep->s, s) == 0; }
bool operator==(const String& x, const String& y)
    { return strcmp(x.rep->s, y.rep->s) == 0; }
bool operator!=(const String& x, const char* s)
    { return strcmp(x.rep->s, s) != 0; }
bool operator!=(const String& x, const String& y)
    { return strcmp(x.rep->s, y.rep->s) != 0; }

String operator+(const String& x, const String& y) {
    String s(x);
    s += y;
    return s;
}

String operator+(const String& x, const char* y) {
    String s(x);
    s += y;
    return s;
}
