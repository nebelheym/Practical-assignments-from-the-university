#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
3.	Поменять местами первую и последнюю буквы первого слова.
*/
int main()
{
    setlocale(LC_CTYPE, "rus");
    string str, s;
    cout << "InputLine: ";
    getline(cin, str, '\n');
    str += " ";
    int len = str.size();
    int i = 0;
    int begin = 0, end = 0;
    int count = 0;
    while (i < str.size() - 1 && count < 1)
    {
        while ((isspace(str[i]) || ispunct(str[i])) && i < str.size() - 1)
            ++i;
        begin = i;
        while (!isspace(str[i]) && !ispunct(str[i]) && i < str.size() - 1)
            ++i;
        end = i;
        count++;
        s = str.substr(begin, end - begin);
    }
    char temp = s[0];
    s[0] = s[s.size() - 1];
    s[s.size() - 1] = temp;
    cout << s;
    return 0;
}