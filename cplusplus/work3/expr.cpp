#include "calculator.hpp"
#include <iostream>
#include <string>
using namespace std;


class Expr {
    string expression;
public:
    Expr(const string str){
        expression = str;
    };
    int eval(){
        return calculator::eval(expression);
    };
    void print(){
        cout << eval() << endl;
    };
};

int main()
{
    string str;
    cin >> str;

    Expr expr(str);
    cout << expr.eval() << endl;
    expr.print();
    return 0;
}
