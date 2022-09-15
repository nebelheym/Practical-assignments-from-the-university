#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
4.	Заменить порядок букв последнего слова  на обратный.
*/
int main()
{
    setlocale(LC_CTYPE, "rus");
    string str, s;
    cout << "InputLine: ";
    getline(cin, str, '\n');
    str += " ";
    str.insert(0, " ");
    int len = str.size();
    int i = len - 2;
    int count = 0;
    int begin, end;
    while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)
        --i;
    end = i;
    while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)
        --i;
    begin = i;
    s = str.substr(begin, end - begin + 1);
    string ns;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (i == s.size() - 1) ns = s[i];
        else ns += s[i];
    }
    cout << ns;
    return 0;
}