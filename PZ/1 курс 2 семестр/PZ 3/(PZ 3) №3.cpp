#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
3. Разработать рекурсивную функцию, которая проверяет,
является ли введенное с клавиатуры
натуральное число простым.
 */
int IsSimple(int numToTest, int divider = 2)
{
    if(divider == numToTest || numToTest == 1) return true;
    if(numToTest%divider == 0) return false;
    else return IsSimple(numToTest, divider + 1);
}
int main()
{
    int simple = IsSimple(16);
    if(simple)
        cout << "Yes";
    else cout << "No";
}