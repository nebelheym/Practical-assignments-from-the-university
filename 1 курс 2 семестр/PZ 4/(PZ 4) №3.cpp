#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
3. Дан файл и строка st. 
Если строка файла содержит в качестве фрагмента строку st, то в начало этой
строки вставить звездочку и пробел
*/
int main()
{
    setlocale(LC_CTYPE, "rus");
    string str;
    string st = "check";
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
        if (str.find(st) != -1)
        {
            cout << "* " << str << endl;
            fout << "* " << str << endl;
        }
    }
    fin.close();  //закрити файл
    fout.close();
    return 0;
}