#include "mystring.hpp"
#include <iostream>
using namespace std;

int main()
{
    String str = "abc";
    String str1 = "edc";
    String str2 = str;
    str1 = str;
    cout << str[1] << endl;
    cout << str << "\n";
    cout << str1 << "\n";
    cout << str2<< "\n";
    return 0;
}
