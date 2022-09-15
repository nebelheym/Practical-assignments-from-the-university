#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
8. Дан файл. 
Слова в строках разделены пробелами. 
Найти строку с наибольшим числом слов.
*/
int WordsCount(string str)
{
    str += " ";
    int len = str.size();
    int i = 0;
    int begin = 0, end = 0;
    int count = 0;
    while (i < str.size() - 1)
    {
        while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)++i;
        begin = i;
        while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)++i;
        end = i;
        count++;
    }
    return count;
}
int StringCount()
{
    string str;
    int count = 0;
    ifstream fin;     // файл для читання
    fin.open("C:\\University\\LB PROG\\input.txt");
    if (!fin.is_open())    // якщо не вдалося відкрити файл
    {
        cout << "Файл не знайдено";
        return 1;
    }
    while (!fin.eof())    // поки не кінець файлу
    {
        getline(fin, str, '\n'); // читання рядка з файлу  
        count++;
    }
    return count;
}
int main()
{
    setlocale(LC_CTYPE, "rus");
    string str;
    int Alpha;
    int count = StringCount();
    int pos;
    int** Matrix = new int* [count];
    for (int i = 0; i < count; i++)
        Matrix[i] = new int[2];
    int MatrixCount = 0;
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
        Matrix[MatrixCount][1] = MatrixCount + 1;
        Matrix[MatrixCount++][0] = WordsCount(str);
    }
    int MaxCount = Matrix[0][0];
    int MaxI = 0;
    for (int i = 1; i < MatrixCount; i++)
        if (MaxCount < Matrix[i][0]) { MaxCount = Matrix[i][0]; MaxI = i; }
    cout << "MaxCount:\t" << MaxCount << "\nString Num:\t" << Matrix[MaxI][1];
    fin.close();  //закрити файл
    fout.close();
    return 0;
}