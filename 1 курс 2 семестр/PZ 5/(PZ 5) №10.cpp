#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
10. Дан файл, содержащий данные об автомобилях. Выполнить следующую обработку данных:
а) Вывести автомобили, произведенные в 1999 или 2001году.
б) Переписать в новый файл номера, марки и стоимости автомобилей заданного цвета.
/*
/*
Пример данных в файле:

BMW 1999 Black 500 BB1231BB
Porche 2022 White 50000 BB3331BB
BMW 2010 Black 1000 BB1531BB
Chevrolet 2015 Blue 4000 BB5631BB
*/
struct avto
{
    string marka;
    int year;
    string color;
    int price;
    string number;
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
        case 5:
            arr[4] = s;
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
        AvtoArr[AvtoCount].price = stoi(strArr[3]);
        AvtoArr[AvtoCount++].number = strArr[4];
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
    int param = 5;
    avto* arr = avtoArrCreate(size, param);
    // а) Вывести автомобили, произведенные в 1999 или 2001году.
    for (int i = 0; i < size; i++)
        if (arr[i].year == 1999 || arr[i].year == 2001)
            cout << arr[i].marka << " " << arr[i].year << " " << arr[i].color << " " << arr[i].price << " " << arr[i].number << endl;
    // б) Переписать в новый файл номера, марки и стоимости автомобилей заданного цвета.
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    string color;
    cout << "Enter color:" << endl;
    cin >> color;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].color == color)
        {
            cout << arr[i].marka << " " << arr[i].year << " " << arr[i].color << " " << arr[i].price << " " << arr[i].number << endl;
            fout << arr[i].marka << " " << to_string(arr[i].year) << " " << arr[i].color << " " << to_string(arr[i].price) << " " << arr[i].number << endl;
        }
    }
    fout.close();
}
int main()
{
    AvtoCheck();
    return 0;
}