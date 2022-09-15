#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
10. Даны три строки. В каждой строке выполнить замену символов: все единицы на нули, все нули на
единицы. Замену выполнять, начиная с заданной позиции строки.
*/
string StringReplacer(string str, int pose)
{
    for (int i = pose; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            str[i] = '0';
            continue;
        }
        else if (str[i] == '0')
        {
            str[i] = '1';
            continue;
        }
    }
    return str;
}
int main()
{
    string arr[3];
    int pos;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter string:" << endl;
        cin >> arr[i];
        cout << "Enter pos: " << endl;
        cin >> pos;
        cout << StringReplacer(arr[i], pos) << endl;
    }
    return 0;
}