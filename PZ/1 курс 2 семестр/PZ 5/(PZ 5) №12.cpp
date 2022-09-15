#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
12. Дан файл, содержащий различные даты (год, месяц, число). Определить самую позднюю дату.
/*
/*
Пример данных в файле:

20 10 2004
17 9 2004
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
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    // а) Найти год с наименьшим номером.
    int* MaxYearArr = new int[size];
    int MaxYearCount = 0;
    int MaxYear = arr[0].year;
    for (int i = 0; i < size; i++)
        if (MaxYear < arr[i].year)
            MaxYear = arr[i].year;
    for (int i = 0; i < size; i++)
        if (arr[i].year == MaxYear)
            MaxYearArr[MaxYearCount++] = i;
    cout << MaxYear << " ";
    if (MaxYearCount > 1)
    {
        int* MaxMonthArr = new int[MaxYearCount];
        int MaxMonthCount = 0;
        int MaxMonth = arr[MaxYearArr[0]].month;
        for (int i = 0; i < MaxYearCount; i++)
            if (MaxMonth < arr[MaxYearArr[i]].month)
                MaxMonth = arr[MaxYearArr[i]].month;
        for (int i = 0; i < MaxYearCount; i++)
            if (arr[MaxYearArr[i]].month == MaxMonth)
                MaxMonthArr[MaxMonthCount++] = i;
        cout << MaxMonth << " ";
        if (MaxMonthCount > 1)
        {
            int* MaxDayArr = new int[MaxMonth];
            int MaxDayCount = 0;
            int MaxDay = arr[MaxMonthArr[0]].day;
            for (int i = 0; i < MaxMonthCount; i++)
                if (MaxDay < arr[MaxYearArr[i]].day)
                    MaxDay = arr[MaxYearArr[i]].day;
            for (int i = 0; i < MaxYearCount; i++)
                if (arr[MaxMonthArr[i]].day == MaxDay)
                    MaxDayArr[MaxDayCount++] = i;
            cout << MaxDay;
        }
        else cout << arr[MaxMonthArr[0]].day;
    }
    else cout << arr[MaxYearArr[0]].month << " " << arr[MaxYearArr[0]].day;
    fout.close();
}
int main()
{
    DateCheck();
    return 0;
}