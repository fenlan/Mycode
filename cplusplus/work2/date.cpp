/* Author: fenlan
 * Date: 2017.4.25
 * -----------------------------------------------------------
 *  	Write functions to add one day, one month, one year to
 * a Date. Write a function that gives the day of the week for
 * a given Date. Write a function that gives the Date of the
 * first Monday following a given Date.
 * -----------------------------------------------------------
 */

#include <iostream>
using namespace std;

short int month_day[12] = {
    31,28,31,30,31,30,31,31,30,31,30,31
};

bool err(short int year, short int month, short int day) {
    if ((year%4==0&&year%100!=0)||(year%400==0))
        month_day[1]++;
    if (month_day[month-1] < day || month > 12)       return false;
    else                                            return true;
}

void add_day(short int &year, short int &month, short int &day) {
    if ((year%4==0&&year%100!=0)||(year%400==0))
        month_day[1]++;

    if (day+1 > month_day[month-1]){
        if (month+1 > 12){
            year++;
            month = 1;
            day = 1;
        }
        else {
            month++;
            day = 1;
        }
    }
    else        day++;

}
bool add_month(short int &year, short int &month, short int &day) {
    if (month+1 > 12) {
        year++;
        month = 1;
    }
    else    month++;

    if (err(year,month,day))   return true;
    else                       return false;
}
void add_year(short int &year, short int &month, short int &day) {
    if ((year%4==0&&year%100!=0)||(year%400==0))
        if (month == 2 && day == 29){
            month++;
            day = 1;
        }
    year++;
}

void next(short int &year, short int &month, short int &day) {
    short int week = 1;
    short int i = 0;
    week = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400) % 7 + 1;
    i = 8 - week;
    for (int k = 0; k < i; k++)
        add_day(year, month, day);
}

int main()
{
    short int year = 2000;
    short int month = 1;
    short int day = 1;
    short int week = 1;
    short int type = 1;

    cin >> year >> month >> day >> type;

    if (!err(year, month, day))  cout << "error!" << endl;
    else {
        week = (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400) % 7 + 1;
        cout << week << endl;

        switch (type) {
            case 1:
            add_year(year, month, day);
            cout << year << " " << month << " " << day << endl;
            break;
            case 2:
            if (add_month(year, month, day))    cout << year << " " << month << " " << day << endl;
            else        cout << "error!" << endl;
            break;
            case 3:
            add_day(year, month, day);
            cout << year << " " << month << " " << day << endl;
            break;
            case 4:
            next(year, month, day);
            cout << year << " " << month << " " << day << endl;
            break;
        }
    }
    return 0;
}
