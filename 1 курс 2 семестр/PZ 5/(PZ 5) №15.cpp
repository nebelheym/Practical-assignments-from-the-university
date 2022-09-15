#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
15. Задан файл с полями: номер видеокассеты, название фильма, фамилия режиссера, год выпуска
фильма.
а) Подсчитать, сколько фильмов каждого года выпуска хранится в файле.
б) Определить, какой режиссер чаще других встречается в файле.
в) Вывести все фильмы в порядке убывания номера кассеты.
/*
/*
Пример данных в файле:

23 ForrestGump Zemekis 1994
12 ShawshankRedemption Darabont 1994
43 Inception Nolan 2010
57 Interstellar Nolan 2014
95 BladeRunner2049 Vilnev 2017
*/
struct Movie
{
    int number;
    string title;
    string producer;
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
        case 4:
            arr[3] = s;
            break;
        }
    }
    return arr;
}
Movie* MovieArrCreate(int& size, int& param)
{
    Movie* MovieArr = new Movie[size];
    int MovieCount = 0;
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
        MovieArr[MovieCount].number = stoi(strArr[0]);
        MovieArr[MovieCount].title = strArr[1];
        MovieArr[MovieCount].producer = strArr[2];
        MovieArr[MovieCount++].year= stoi(strArr[3]);
    }
    fin.close();  //закрити файл
    return MovieArr;
}
void MovieCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 4;
    Movie* arr = MovieArrCreate(size, param);
    // а) Подсчитать, сколько фильмов каждого года выпуска хранится в файле.
    int* YearArr = new int[size];
    int YearArrCount = 0;
    bool flag;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < YearArrCount; j++)
        {
            if (arr[i].year == YearArr[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) YearArr[YearArrCount++] = arr[i].year;
    }
    int* CountOfYears = new int[YearArrCount];
    for (int i = 0; i < YearArrCount; i++)
    {
        CountOfYears[i] = 0;
        for (int j = 0; j < size; j++)
            if (YearArr[i] == arr[j].year)
                CountOfYears[i]++;
        cout << "Films of " << YearArr[i] << " release " << CountOfYears[i] << endl;
    }
    // б) Определить, какой режиссер чаще других встречается в файле.
    string* ProducerArr = new string[size];
    int ProducerArrCount = 0;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < ProducerArrCount; j++)
        {
            if (arr[i].producer == ProducerArr[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) ProducerArr[ProducerArrCount++] = arr[i].producer;
    }
    int* CountOfProducer = new int[ProducerArrCount];
    for (int i = 0; i < ProducerArrCount; i++)
    {
        CountOfProducer[i] = 0;
        for (int j = 0; j < size; j++)
            if (ProducerArr[i] == arr[j].producer)
                CountOfProducer[i]++;
    }
    int max = -1; // Потому что не может быть меньше 0 продюсеров
    for (int i = 0; i < ProducerArrCount; i++)
        if (max < CountOfProducer[i])
            max = CountOfProducer[i];
    for (int i = 0; i < ProducerArrCount; i++)
        if (CountOfProducer[i] == max)
        {
            cout << "Most Popular Producer is " << ProducerArr[i] << endl;
            break;
        }
    // в) Вывести все фильмы в порядке убывания номера кассеты.
    Movie temp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (arr[j].number < arr[j + 1].number)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    for (int i = 0; i < size; i++)
        cout << "Number: " << arr[i].number << " Title: " << arr[i].title << " Producer: " << arr[i].producer << " Year: " << arr[i].year << endl;
}
int main()
{
    MovieCheck();
    return 0;
}