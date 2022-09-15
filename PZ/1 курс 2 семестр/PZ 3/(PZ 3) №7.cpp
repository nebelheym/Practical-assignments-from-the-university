#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
7. Написать функцию, которая вводит строку и определяет, является ли она палиндромом. Палиндром
– это число или текст, который одинаково читается слева направо и справа налево. Например, 12321, 55555.
Объявить указатель на функцию. Вызвать функцию через этот указатель.
 */
bool is_palindrome(string str)
{
    if (str.size() < 1) return true;
    else if (str[0] == str[str.size()-1]) return is_palindrome(str.substr(1, str.size() - 2));
    else return false;
}
int main()
{
    string str;
    cout << "Enter str:" << endl;
    cin >> str;
    bool (*palindrome)(string) = &is_palindrome;
    if(palindrome(str)) cout << "Yes";
    else cout << "No";
}