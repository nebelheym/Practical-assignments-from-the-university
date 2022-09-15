#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
11. Дан файл. Слова в строках разделены пробелами. 
В каждой строке найти самое короткое слово и его номер.
*/
void WordsCount(string str)
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
    string s;
    string* WordsArr = new string[count];
    count = 0;
    i = 0;
    while (i < str.size() - 1)
    {
        while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)++i;
        begin = i;
        while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)++i;
        end = i;
        s = str.substr(begin, end - begin);
        WordsArr[count++] = s;
    }
    int min = WordsArr[0].size();
    int minI = 0;
    for(int i = 1; i < count; i++)
        if (min > WordsArr[i].size()){min = WordsArr[i].size();minI = i;}
    cout << "Min: " << min << "\tIndex: " << minI+1 << endl;
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
        WordsCount(str);
        cout << str << endl;
        fout << str << endl;
    }
    fin.close();  //закрити файл
    fout.close();
    return 0;
}