/* Author: fenlan
 * Date: 2017.4.18
 * ---------------------------------------------
 *   A desk calculator that provides the four
 * standard arithmetic operations as infix
 * operators on floating-point numbers. The user
 * can also define varibles. The calculator
 * consists of four main parts: a parser, an 
 * input function, a symbol table, and a driver.
 * ---------------------------------------------
 */

/*
在加减运算上，一个数和一个乘除运算都是加减运算的一个项，而括号不论对加减还是乘除运算，都算一个项。做个简答的例子解释：
                            86+24*32
程序最先读取number 86，当读取到 + 时将86作为加法的左项，接着读取 number 24，再读取乘法，此时24 作为了乘法的左项，
最后读取32作为乘法的右项，读取结束。此时乘法的左项与乘法的右项做乘运算得到结果，该结果作为加法的右项，接着递归回加法运算，
加法的左项与右项做加法运算得到最终的计算结果。Ok，解释了一会儿感觉自己思路又清晰了许多，只是不知道对别人解释能不能解释清楚。
*/

#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

map<string, double> table;

int no_of_errors;
double number_value;
string string_value;

enum Token_value {
    NAME,       NUMBER,     END,
    PLUS='+',   MINUS='-',  MUL='*',    DIV='/',
    PRINT=';',  ASSIGN='=', LP='(',     RP=')'
};
Token_value curr_tok = PRINT;

double expr(bool get);

double term(bool get);

double prim(bool get);

Token_value get_token();

double error(const string& s);

int main()
{
    table["pi"] = 3.1415926;
    table["e"] = 2.7182818;

    while (cin) {
        get_token();
        if (curr_tok == END) break;
        if (curr_tok == PRINT) continue;
        cout << expr(false) << endl;
    }

    return no_of_errors;
}

double expr(bool get)
{
    double left = term(get);

    for (;;)
        switch (curr_tok) {
            case PLUS:
                left += term(true);
                break;
            case MINUS:
                left -= term(true);
                break;
            default:
                return left;
        }
}

double term(bool get)
{
    double left = prim(get);

    for (;;)
        switch (curr_tok) {
            case MUL:
                left *= prim(true);
                break;
            case DIV:
                if (double d=prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
}

double prim(bool get)
{
    if (get) get_token();

    switch (curr_tok) {
        case NUMBER:
        {
            double v = number_value;
            get_token();
            return v;
        }
        case NAME:
        {
            double& v = table[string_value];
            if (get_token() == ASSIGN) v = expr(true);
            return v;
        }
        case MINUS:
            return -prim(true);
        case LP:
        {
            double e = expr(true);
            if (curr_tok != RP) return error(") expected");
            get_token();
            return e;
        }
        default:
            return error("primary expected");
    }
}

Token_value get_token()
{
    char ch = 0;
    cin >> ch;

    switch (ch) {
        case 0:
            return curr_tok = END;
        case ';':
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return curr_tok = Token_value(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            cin.putback(ch);
            cin >> number_value;
            return curr_tok = NUMBER;
        default:
            if (isalpha(ch)) {
                char v[100];
                cin.putback(ch);
                for (int i=0;; i++){
                    cin >> v[i];
                    if (v[i] < 'A' || v[i] > 'z'){
                        cin.putback(v[i]);
                        v[i] = '\0';
                        break;
                    }
                }
                string_value = v;
                //cout << string_value << endl;
                return curr_tok = NAME;
            }
            error("bad token");
            return curr_tok = PRINT;
    }
}

double error(const string& s)
{
    no_of_errors++;
    cerr << "error: " << s << endl;
    return 1;
}
