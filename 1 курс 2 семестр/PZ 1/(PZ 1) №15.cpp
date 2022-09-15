#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
15. Даны три строки. Используя функцию, определить позицию самого первого вхождения заданного
символа в каждую из строк. Если строка не содержит символ, результатом работы функции должна быть –1.
*/
int FirstFind(string str)
{
    char key;
    int pos;
    cout << "Enter key: " << endl;
    cin >> key;
    bool flag = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == key)
        {
            flag = true;
            pos = i + 1;
            break;
        }
    }
    if (flag) return pos;
    else return -1;
}
int main()
{
    string str;
    cout << "Enter string: " << endl;
    cin >> str;
    int pos = FirstFind(str);
    cout << "Position: " << pos << endl;
    return 0;
}