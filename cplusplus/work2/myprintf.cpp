/* Author: fenlan
 * Date:2017.4.25
 * -----------------------------------
 *  	Write an error function that
 * that takes a printf-style format
 * string containing %s, %c, and %d
 * directives and an arbitrary number
 * of arguments. Don't use printf().
 * Use <cstdarg>
 */

#include <iostream>
#include <cstdarg>
#include <stdio.h>
using namespace std;

void PrintStr(char* str) {
	while(*str != '\0')
	putchar(*str++);
}

void PrintChar(char c) {
	putchar(c);
}

void PrintInt(int i) {
	int sign = i>0 ? 0 : 1;
	char s[10];
	int cnt=0;
	if(sign)
	{
		putchar('-');
		i = -i;
	}
	int ten = i%10;
	while(i)
	{
		s[cnt] = ten+'0';
		cnt++;
		i /= 10;
		ten = i%10;
	}
	while(cnt>=0)
	putchar(s[--cnt]);
}

void myprintf(char* content, ...) {
	va_list arg_ptr;
	char* str = content;
	int x;
	char y;
	char* s;
	va_start(arg_ptr, content);
	do
	{
		if(*str != '%')
		putchar(*str++);
		else
		{
			switch(*(++str))
			{
				case('d'):
				x = va_arg(arg_ptr,int);
				//printf("x=%d\n", x);
				PrintInt(x);
				break;
				case('c'):
				y = va_arg(arg_ptr,int);
				//PrintInt(y);
				PrintChar(y);
				break;
				case('s'):
				s = va_arg(arg_ptr,char*);
				//printf("%s\n", s);
				PrintStr(s);
				break;
				default:
				myprintf("I need relax.");
			}
			str++;
		}
	}while(*str != '\0');
}



int main(int argc, char* argv[])
{
	char a = 't';
	myprintf("a = %c\n", a);
	return 1;
}
