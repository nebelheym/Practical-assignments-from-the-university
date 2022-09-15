#include <iostream>
using namespace std;
int main()
{
    int day, week, year, seconds_day, seconds_week, seconds_year;
    cout << "Enter the number of days:" << endl;
    cin >> day;
    cout << "Enter the number of weeks:" << endl;
    cin >> week;
    cout << "Enter the number of years:" << endl;
    cin >> year;
    seconds_day = 60*60*24*day;
    seconds_week = seconds_day * 7 * week;
    seconds_year = seconds_day * 365 * year;
    cout << seconds_day << " seconds in " << day << " day(s)" << endl;
    cout << seconds_week << " seconds in " << week << " week(s)" << endl;
    cout << seconds_year << " seconds in " << year << " year(s)" << endl;
    return 0;
}