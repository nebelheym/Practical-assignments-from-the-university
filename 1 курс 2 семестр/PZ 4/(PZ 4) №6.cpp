#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
6. Дан файл, содержащий программу на языке С++.
Проверить эту программу на несоответствие числа
открывающих и закрывающих фигурных скобок
*/
void CurlyBracesCheck(string str, int& count)
{
    for (int i = 0; i < str.size(); i++)
        if (str[i] == '{' || str[i] == '}') count++;
}
int main()
{
    setlocale(LC_CTYPE, "rus");
    string str;
    string st = "check";
    int count = 0;
    ifstream fin;     // файл для читання
    fin.open("C:\\University\\LB PROG\\input.txt");
    ofstream fout;    // файл для запису відсортованого масиву
    fout.open("C:\\University\\LB PROG\\output.txt");
    if (!fin.is_open())    // якщо не вдалося відкрити файл
    {
        cout << "Файл не знайдено";
        return 1;
    }
    while (!fin.eof())    // поки не кінець файлу
    {
        getline(fin, str, '\n'); // читання рядка з файлу
        CurlyBracesCheck(str, count);
        cout << str << endl;
    }
    if (count % 2 == 0) cout << "Even";
    else "Not Ever";
    fin.close();  //закрити файл
    fout.close();
    return 0;
}