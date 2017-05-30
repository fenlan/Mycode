#include <iostream>
using namespace std;

struct S { int x, y; };
struct T { const char* p; const char* q; };

class C
{
public:
    int& x;
    const char*& p;

    C(S s, T t) : x(s.x), p(t.p)
    {
    }
};

int main()
{
    S s = { 1, 2 };
    T t = { "hello", "world" };
    C c(s, t);

    cout << c.x << ' ' << c.p << endl;

    return 0;
}
