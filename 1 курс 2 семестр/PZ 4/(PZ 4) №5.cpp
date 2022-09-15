#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
5. Дан файл. 
Преобразовать строки файла следующим образом:
если строка является палиндромом, т.е. 1-й
ее символ равен последнему, 2-й - предпоследнему и т.д., то оставить ее без изменения,
иначе строку удвоить, дописав в ее конец эту же строку. Результат поместить в новый файл.
*/
string PalindromeCheck(string str)
{
    bool flag = false;
    for (int i = 0; i < str.size() / 2; i++)
        if (str[i] == str[str.size() - 1 - i]) flag = true;
    if (!flag) str += str;
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
        str = PalindromeCheck(str);
        cout << str << endl;
        fout << str << endl;
    }
    fin.close();  //закрити файл
    fout.close();
    return 0;
}