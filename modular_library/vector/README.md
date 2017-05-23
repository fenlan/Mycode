# <p align="center">Vector</p>

## A Vector Class
Here is a more realistic version of class `Vector`. I write this to `math vector`, such as `v(x,y)`,`v(x,y,z)`. This vector provides interface calculating math vector additive, subtraction, multiplication and division.

## Interface
- `+`: v1(x1,y1)+v2(x2,y2) = v(x1+x2,y1+y2)
- `-`: v1(x1,y1)-v2(x2,y2) = v(x1-x2,y1-y2)
- `*`: v1(x1,y1)`*`v2(x2,y2) = v(x1`*`x2,y1`*`y2)
- `/`: v1(x1,y1)/v2(x2,y2) = v(x1/x2,y1/y2), but without exception handing
- `+=`: as int operator `+=`
- `-=`: as int operator `-=`
- `*=`: as int operator `*=`
- `/=`: as int operator `/=`
- `=`: assignment from other vector

## Example
```
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
```
`output`
> [2,3,4,5]
>
>	[1,2,3,4] + [2,2,2,2] = [3,4,5,6]
>
>	[1,2,3,4] - [2,2,2,2] = [-1,0,1,2]
>
>	[1,2,3,4] * [2,2,2,2] = [2,4,6,8]
>
>	[1,2,3,4] / [2,2,2,2] = [0.5,1,1.5,2]

## Reference
[2]this guy's program [bretternst](https://github.com/bretternst/tcpppl_answers/blob/master/ch11/ex15.cpp)

## Update
`2015.5.23` There is minimal math vector class. If possible, add more later
