#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
16. Задан файл с полями: название музея, страна, город, количество экспонатов. 
Определить в какой стране больше всего музеев и в каком музее этой страны больше всего экспонатов.
/*
/*
Пример данных в файле:

National USA NewYourk 123
Zoo Japan Tokyo 400
Military USA California 245
*/
struct Museum
{
    string name;
    string country;
    string city;
    int number;
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
Museum* MuseumArrCreate(int& size, int& param)
{
    Museum* MuseumArr = new Museum[size];
    int MuseumCount = 0;
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
        MuseumArr[MuseumCount].name = strArr[0];
        MuseumArr[MuseumCount].country = strArr[1];
        MuseumArr[MuseumCount].city = strArr[2];
        MuseumArr[MuseumCount++].number= stoi(strArr[3]);
    }
    fin.close();  //закрити файл
    return MuseumArr;
}
void MuseumCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 4;
    Museum* arr = MuseumArrCreate(size, param);
    // Определить в какой стране больше всего музеев и в каком музее этой страны больше всего экспонатов.
    string* Country = new string[size];
    int CountryCount = 0;
    bool flag;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < CountryCount; j++)
        {
            if (arr[i].country == Country[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) Country[CountryCount++] = arr[i].country;
    }
    int* Popularity = new int[CountryCount];
    for (int i = 0; i < CountryCount; i++)
    {
        Popularity[i] = 0;
        for (int j = 0; j < size; j++)
            if (Country[i] == arr[j].country)
                Popularity[i]++;
    }
    string maxName;
    int max = Popularity[0];
    for (int i = 1; i < CountryCount; i++)
        if (Popularity[i] > max)
            max = Popularity[i];
    for (int i = 0; i < CountryCount; i++)
        if (Popularity[i] == max)
        {
            maxName = Country[i];
            break;
        }
    cout << "Most museums in " << maxName << endl;
    max = -1; // Потому что не может быть меньше 0 экспонатов
    for (int i = 0; i < size; i++)
        if (arr[i].country == maxName)
            if (max < arr[i].number)
                max = arr[i].number;
    for(int i = 0; i < size; i++)
        if (arr[i].country == maxName && arr[i].number == max)
        {
            cout << "Name: " << arr[i].name << endl;
            cout << "Country: " << arr[i].country << endl;
            cout << "City: " << arr[i].city << endl;
            cout << "Number: " << arr[i].number << endl;
            break;
        }
}
int main()
{
    MuseumCheck();
    return 0;
}