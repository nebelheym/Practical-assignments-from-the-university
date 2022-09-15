#include <iostream>
#include<string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
/*
Задание 2.3. 
Создайте перегруженную функцию sum, которая находит сумму двух целых чисел,
трех вещественных чисел и сумму кодов четырех символов.
*/
int sum(int v1, int v2)
{
    return v1 + v2;
}
double sum(double v1, double v2, double v3)
{
    return v1 + v2 + v3;
}
int sum(char v1, char v2, char v3, char v4)
{
    return v1 + v2 + v3 + v4;
}
int main()
{
    cout << sum(1, 4) << endl;
    cout << sum(6.7, 4.5, 6) << endl;
    cout << sum('s', '1', '}', '0');
    return 0;
}