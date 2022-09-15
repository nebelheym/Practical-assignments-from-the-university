#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
7. В файле заменить каждую цифру на следующую по величине цифру (‘9’ заменить на ‘0’), 
результат
поместить в новый файл.
*/
string DigitSwap(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]) && str[i] != '9') str[i] += 1;
        else if (str[i] == '9') str[i] = '0';
    }
    return str;
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
        str = DigitSwap(str);
        cout << str << endl;
        fout << str << endl;
    }
    fin.close();  //закрити файл
    fout.close();
    return 0;
}