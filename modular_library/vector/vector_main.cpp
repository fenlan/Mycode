#include "vector.hpp"
using namespace std;

int main()
{
    Vector x;
    x[0] = 1.0f;
    x[1] = 2.0f;
    x[2] = 3.0f;
    x[3] = 4.0f;

    Vector y;
    y[0] = 2.0f;
    y[1] = 2.0f;
    y[2] = 2.0f;
    y[3] = 2.0f;

    cout << 1.0f + x << endl;

    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;

    return 0;
}
