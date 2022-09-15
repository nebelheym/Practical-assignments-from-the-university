#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
14. Для файла, содержащего данные об автомобилях, выполнить следующую обработку данных:
а) Подсчитать среднюю стоимость автомобилей и самый дорогой автомобиль каждого цвета.
б) Определить самую популярную марку автомобиля.
/*
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
    // а) Подсчитать среднюю стоимость автомобилей и самый дорогой автомобиль каждого цвета.
    int average = 0;
    for (int i = 0; i < size; i++)
        average += arr[i].price;
    average /= size;
    cout << "Average price: " << average << endl;
    string* ColorArr = new string[size];
    int ColorArrCount = 0;
    bool flag;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < ColorArrCount; j++)
        {
            if (arr[i].color == ColorArr[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) ColorArr[ColorArrCount++] = arr[i].color;
    }
    int max;
    for (int i = 0; i < ColorArrCount; i++)
    {
        max = -1; // Потому что цена не может быть отрицательной
        for (int j = 0; j < size; j++)
        {
            if (ColorArr[i] == arr[j].color)
            {
                if (arr[j].price > max)
                    max = arr[j].price;
            }
        }
        cout << "Max price for " << ColorArr[i] << ": " << max << endl;
    }
    // б) Определить самую популярную марку автомобиля.
    string* Models = new string[size];
    int ModelsCount = 0;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < ModelsCount; j++)
        {
            if (arr[i].marka == Models[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) Models[ModelsCount++] = arr[i].marka;
    }
    int* Popularity = new int[ModelsCount];
    for (int i = 0; i < ModelsCount; i++)
    {
        Popularity[i] = 0;
        for (int j = 0; j < size; j++)
            if (Models[i] == arr[j].marka)
                Popularity[i]++;
    }
    max = -1; // Потому что популярность не может быть ниже 0
    for (int i = 0; i < ModelsCount; i++)
        if (Popularity[i] > max)
            max = Popularity[i];
    for (int i = 0; i < ModelsCount; i++)
    {
        if (Popularity[i] == max)
        {
            cout << "Most popular car brand is " << Models[i] << endl;
            break;
        }
    }
}
int main()
{
    AvtoCheck();
    return 0;
}