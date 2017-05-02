#include <iostream>
using namespace std;

struct Date {
	int day, month, year;
};

const int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int countLeapYears(Date dt);
int getDifference(Date dt1, Date dt2);

int main()
{
	Date dt1 = {1, 1, 1970};
	Date dt2 = {1, 2, 1971};

	cout << "Difference between two dates is: " << getDifference(dt1, dt2) << endl;
	return 0;    
}

int countLeapYears(Date dt) {
	int years = dt.year;

	if (dt.month <= 2)
		years--;

	return years / 4 - years / 100 + years / 400;
}

int getDifference(Date dt1, Date dt2) {
	long int n1 = dt1.year * 365 + dt1.day;

	for (int i=0; i<dt1.month - 1; i++)
		n1 += monthDay[i];
	n1 += countLeapYears(dt1);

	long int n2 = dt2.year * 365 + dt2.day;

	for (int i=0; i<dt2.month - 1; i++)
		n2 += monthDay[i];
	n2 += countLeapYears(dt2);

	return (n2 - n1);
}
