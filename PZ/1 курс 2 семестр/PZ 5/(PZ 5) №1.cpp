#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
1. Создать структуру Дата с элементами День, Месяц, Год. 
Для N человек с заданной датой рождения вывести
сообщение, в каком сезоне и в каком веке родился человек.
*/
struct Human
{
    int day;
    int month;
    int year;
};
int main()
{
    cout << "Enter N:" << endl;
    int N;
    cin >> N;
    Human* arr = new Human[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i + 1 << " Human:" << endl;
        cout << "Day:" << endl;
        cin >> arr[i].day;
        cout << "Month:" << endl;
        cin >> arr[i].month;
        cout << "Year:" << endl;
        cin >> arr[i].year;
    }
    for (int i = 0; i < N; i++)
    {
        cout << i+1 << " Human seasone is ";
        if (arr[i].month == 12 || arr[i].month == 1 || arr[i].month == 2)
            cout << "winter ";
        else if (arr[i].month == 3 || arr[i].month == 4 || arr[i].month == 5)
            cout << "spring ";
        else if (arr[i].month == 6 || arr[i].month == 7 || arr[i].month == 8)
            cout << "summer ";
        else if (arr[i].month == 9 || arr[i].month == 10 || arr[i].month == 11)
            cout << "autumn ";
        cout << "and century is ";
        if (arr[i].year > 2000) cout << "XX" << endl;
        else if (arr[i].year > 2001 && arr[i].year > 1900) cout << "XIX" << endl;
        else cout << "lol :D" << endl;
    }
    return 0;
}