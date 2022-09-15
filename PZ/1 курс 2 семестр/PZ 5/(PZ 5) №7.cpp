#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
7. Дан файл f, содержащий даты: число, месяц, год.
а) Найти год с наименьшим номером.
б) В файл g переписать осенние даты с четными числами, а в файл h– все весенние с нечетными числами.
*/
/*
Пример данных в файле:

20 10 2003
17 4 2004
7 4 2002
*/
struct Date
{
    int day;
    int month;
    int year;
};
string* edStr(string str, int& param)
{
    string nst, s;
    str += " ";
    int len = str.size(); //довжина введеного тексту
    int i = 0;
    string* arr = new string[param];
    int begin = 0, end = 0, count = 0;
    while (i < str.size() - 1)
    {
        while (isspace(str[i]) || ispunct(str[i]))
            ++i;      // пропустити пробіли 
        begin = i;                       // номер першого символу слова
        while (!isspace(str[i]) && !ispunct(str[i]))
            ++i;                       // пропустити символи слова
        end = i;     // номер символу, наступного за останнім символом слова
        s = str.substr(begin, end - begin);
        count++;
        switch (count)
        {
        case 1:
            arr[0] = s;
            break;

        case 2:
            arr[1] = s;
            break;

        case 3:
            arr[2] = s;
            break;
        }
    }
    return arr;
}
Date* DateArrCreate(int& size, int& param)
{
    Date* DateArr = new Date[size];
    int DateCount = 0;
    string str;
    string* strArr = new string[param];
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    if (!fin.is_open())
    {
        cout << "File does not open!" << endl;
        return NULL;
    }
    while (!fin.eof())
    {
        getline(fin, str, '\n');
        strArr = edStr(str, param);
        DateArr[DateCount].day = stoi(strArr[0]);
        DateArr[DateCount].month = stoi(strArr[1]);
        DateArr[DateCount++].year = stoi(strArr[2]);
    }
    fin.close();  //закрити файл
    return DateArr;
}
void DateCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 3;
    Date* arr = DateArrCreate(size, param);
    ofstream g, h;
    g.open("C:\\University\\LB PROG\\output.txt"); // предположим что он g
    h.open("C:\\University\\LB PROG\\output.txt"); // предположим что он h
    // а) Найти год с наименьшим номером.
    int min = arr[0].year;
    for (int i = 1; i < size; i++)
        if (arr[i].year < min)
            min = arr[i].year;
    cout << "Min year is " << min << endl;
    // В файл g переписать осенние даты с четными числами, а в файл h – все весенние с нечетными числами.
    for (int i = 0; i < size; i++)
    {
        if ((arr[i].month >= 9 && arr[i].month <= 11) && arr[i].day % 2 == 0)
        {
            cout << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
            g << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
        }
        if ((arr[i].month >= 3 && arr[i].month <= 5) && arr[i].day % 2 != 0)
        {
            cout << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
            h << arr[i].day << "." << arr[i].month << "." << arr[i].year << endl;
        }
    }
    g.close();
    h.close();
}
int main()
{
    DateCheck();
    return 0;
}