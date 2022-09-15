#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
9. Дан файл. Слова в строках разделены пробелами. 
В строках с четными номерами записать слова в
обратном порядке
*/
string WordsCount(string str)
{
    str += " ";
    int len = str.size();
    int i = 0;
    int begin = 0, end = 0;
    int count = 0;
    while (i < str.size() - 1)
    {
        while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)++i;
        while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)++i;
        count++;
    }
    if (count % 2 == 0)
    {
        string* WordsArr = new string[count];
        i = 0;
        count = 0;
        string s;
        while (i < str.size() - 1)
        {
            while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)++i;
            begin = i;
            while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)++i;
            end = i;
            s = str.substr(begin, end - begin);
            WordsArr[count++] = s;
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = WordsArr[i].size() - 1; j >= 0; j--)
            {
                if (i == 0 && j == WordsArr[i].size() - 1) str = WordsArr[i][j];
                else str += WordsArr[i][j];
            }
            str += " ";
        }
    }
    return str;
}
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
        str = WordsCount(str);
        cout << str << endl;
        fout << str << endl;
    }
    fin.close();  //закрити файл
    fout.close();
    return 0;
}