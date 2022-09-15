#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
5. Возвести целое число в целую степень.
Число и степень вводятся с клавиатуры.
Все умножения должны выполняться рекурсивной функцией.
 */
int MyPow(int num, int degree)
{
    if(degree == 1) return num;
    else return num*MyPow(num, degree-1);
}
int main()
{
    int power = MyPow(2, 5);
    cout << "MyPow: " << power << endl;
}