/* Author: fenlan
 * Date: 2017.4.9
 * ----------------------------------------------------
 *   write a function atoi(const char*) that takes a
 * C-style string containing digits and returns the
 * corresponding int. For example, aroi("123") is 123.
 * Modify atoi() to handle c++ octal and hexadecimal
 * notation in addition to plain decimal numbers. Modify
 * atoi() to handle the c++ character constant notation.
 * ----------------------------------------------------
 */


#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

typedef vector<int> INT_AYY;
const int MAX = 200;

INT_AYY my_atoi(char *);
// take a C-style string containing digits and
// return the corresponding int

int conver(char *);
// conversion string to int

int only_digits_con(char *substring, int begin, int end, int base);
// take the range of digits and return corresponding int,
// the base is one of (2, 8, 10, 16)

int main()
{
	INT_AYY substring_int;
	char string[MAX] = "1234 -1234 +1234 01234 -01234 +01234 0x1234 -0x1234 +0x1234";

	substring_int = my_atoi(string);
	for (int i = 0; i < substring_int.size(); i++)
		cout << substring_int[i] << " " ;

	cout << endl;

	return 0;
}

INT_AYY my_atoi(char *string)
{
	INT_AYY substring_int;
	const int HIGH = 20;
	int i = 0, j = 0, k = 0;
	char substring[HIGH][HIGH];

	while (true) {
		if (string[i] == '\0' || i == MAX)     break;
		if (string[i] == 32) {   //white-space
			substring[j][k] = '\0';
			k = 0;
			i++;
			j++;
			continue;
		}
		substring[j][k] = string[i];
		i++;
		k++;
	}

	for (i = 0; i <= j; i++) {
		int v = 0;
		v = conver(substring[i]);
		substring_int.push_back(v);
	}

	return substring_int;
}

int conver(char *substring)
{
	int bite = 0;
	int con_value = 0;

	for (bite = 0; substring[bite] != '\0'; bite++);    //get str_length
	if (substring[0] == '-') {
		if (substring[1] == '0' && substring[2] == 'x')
			con_value = only_digits_con(substring, 3, bite-1, 16);
		else if (substring[1] == '0')
			con_value = only_digits_con(substring, 2, bite-1, 8);
		else
			con_value = only_digits_con(substring, 1, bite-1, 10);

		con_value = 0 - con_value;
	}
	else if (substring[0] == '+') {
		if (substring[1] == '0' && substring[2] == 'x')
			con_value = only_digits_con(substring, 3, bite-1, 16);
		else if (substring[1] == '0')
			con_value = only_digits_con(substring, 2, bite-1, 8);
		else
			con_value = only_digits_con(substring, 1, bite-1, 10);
	}
	else if (substring[0] == '0') {
		if (substring[1] == 'x')
			con_value = only_digits_con(substring, 2, bite-1, 16);
		else
			con_value = only_digits_con(substring, 1, bite-1, 8);
	}
	else
		con_value = only_digits_con(substring, 0, bite-1, 10);

	return con_value;
}

int only_digits_con(char *substring, int begin, int end, int base)
{
	int substring_int = 0;

	for (int i = begin; i <= end; i++){
		if (isdigit(substring[i]))
			substring_int = substring_int*base + substring[i] - '0';
		else
			substring_int = substring_int*base + substring[i] - 'A' + 10;
	}

	return substring_int;
}
