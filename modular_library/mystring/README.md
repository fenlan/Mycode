# <p align="center">String</p>
## A String Class
Here is a more realistic version of class `String`. I copy the interfaces from `the c++ programming language(special edition)`. This string provides value semantics, character read and write operations, checked and unchecked access, stream I/O, literal strings as literals, and equality and concatenation operators. It represents string as C-style, zero-terminated arrays of characters and uses reference counts to minimize copying.

## Interface
- `=`: copy string value
- `+=`: str1 += str2
- `>>`: istream for string
- `<<`: ostream for string
- `==`: equality operator
- `!=`: inequality operator
- `+`: str1 + str2
- `check(i)`: check for correctness of argument's value
- `read(i) const`: read a char of string
- `write(i, c)`: write c value in string
- `size()`: return size of string
- `string[]`: get a char from a string

## Example
```
String str = "abc";
String str1 = "edc";
String str2 = str;
str1 = str;
cout << str[1] << endl;
cout << str << endl;
cout << str1 << endl;
cout << str2 << endl;
```
`output`
> b
>
> abc
>
> abc
>
> abc

## Reference
[1]the c++ programming language(special edition) by Bjarne Stroustrup

[2]this guy's program [bretternst](https://github.com/bretternst/tcpppl_answers/blob/master/ch11/string.cpp)

## Update
There is minimal string class. If possible, add more later
*2015.5.23*