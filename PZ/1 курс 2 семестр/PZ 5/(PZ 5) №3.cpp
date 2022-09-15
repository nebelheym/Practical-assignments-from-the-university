#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
3. Информацию о наличии на складе автомашин можно представить с помощью таких полей: модель
(marka), год выпуска (year), цвет (color) и цена машины (price). Описать структуру avto. Создать
файл из шести-семи записей, который содержит информацию об автомобилях. Вывести содержимое
файла на экран для контроля. Используя созданный файл, составить программу для получения
следующих сведений:
а) Определить количество и вывести на экран названия моделей, которые выпускались в 1999 году.
б) Вывести в файл Y информацию о машинах черного цвета, выпущенных за последние пять лет.
в) Получить информацию о самой дорогой и самой дешевой машине.
г) Получить информацию о самой старой и самой современной машине.
д) Получить информацию о машинах данной модели и данного цвета.
*/
/*
Пример данных в файле:

BMW 1999 Black 500
Porche 2022 White 50000
BMW 2010 Black 10000
Chevrolet 2015 Blue 4000
*/
struct avto
{
    string marka;
    int year;
    string color;
    int price;
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
avto* avtoArrCreate(int& size, int& param)
{
    avto* AvtoArr = new avto[size];
    int AvtoCount = 0;
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
        AvtoArr[AvtoCount].marka = strArr[0];
        AvtoArr[AvtoCount].year = stoi(strArr[1]);
        AvtoArr[AvtoCount].color = strArr[2];
        AvtoArr[AvtoCount++].price = stoi(strArr[3]);
    }
    fin.close();  //закрити файл
    return AvtoArr;
}
void AvtoCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 4;
    avto* arr = avtoArrCreate(size, param);
    // а) Определить количество и вывести на экран названия моделей, которые выпускались в 1999 году.
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].year == 1999)
        {
            cout << arr[i].marka << endl;
            count++;
        }
    }
    cout << "Count of 1999 year avto is " << count << endl;
    // б) Вывести в файл Y информацию о машинах черного цвета, выпущенных за последние пять лет.
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    for (int i = 0; i < size; i++)
    {
        if (arr[i].year > 2017 && arr[i].color == "Black")
        {
            cout << arr[i].marka << " " << arr[i].year << " " << arr[i].color << " " << arr[i].price << endl;
            fout << arr[i].marka << " " << to_string(arr[i].year) << " " << arr[i].color << " " << to_string(arr[i].price) << endl;
        }
    }
    fout.close();
    // в) Получить информацию о самой дорогой и самой дешевой машине.
    int max = arr[0].price;
    int min = arr[0].price;
    int maxI = 0;
    int minI = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i].price)
        {
            max = arr[i].price;
            maxI = i;
        }
        if (min > arr[i].price)
        {
            min = arr[i].price;
            minI = i;
        }
    }
    cout << "Most expensive avto is " << arr[maxI].marka << " " << arr[maxI].year << " " << arr[maxI].color << " " << arr[maxI].price << endl;
    cout << "Cheapest avto is " << arr[minI].marka << " " << arr[minI].year << " " << arr[minI].color << " " << arr[minI].price << endl;
    // г) Получить информацию о самой старой и самой современной машине.
    max = arr[0].year;
    min = arr[0].year;
    maxI = 0;
    minI = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i].year)
        {
            max = arr[i].year;
            maxI = i;
        }
        if (min > arr[i].year)
        {
            min = arr[i].year;
            minI = i;
        }
    }
    cout << "The most modern avto is " << arr[maxI].marka << " " << arr[maxI].year << " " << arr[maxI].color << " " << arr[maxI].price << endl;
    cout << "The oldest avto is " << arr[minI].marka << " " << arr[minI].year << " " << arr[minI].color << " " << arr[minI].price << endl;
    // д) Получить информацию о машинах данной модели и данного цвета.
    string model;
    string color;
    cout << "Enter model and color:" << endl;
    cin >> model;
    cin >> color;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].marka == model && arr[i].color == color)
            cout << "Information about the avto you are interested is " << arr[i].marka << " " << arr[i].year << " " << arr[i].color << " " << arr[i].price << endl;
    }
}
int main()
{
    AvtoCheck();
    return 0;
}