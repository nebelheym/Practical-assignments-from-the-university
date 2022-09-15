#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
2.	Определить количество гласных в последнем слове строки.
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
    string Vowels("AEIOUYaeiouy");
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < Vowels.size(); j++)
            if (s[i] == Vowels[j])
                count++;
    cout << "Count of vowels " << count;
    return 0;
}