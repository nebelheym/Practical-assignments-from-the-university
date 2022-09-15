#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
4. Найти наибольший общий делитель двух натуральных чисел, вводимых с клавиатуры, с помощью
алгоритма Евклида (Большее из чисел заменяется разностью этих чисел. Этот процесс повторяется до тех
пор, пока не останется одно ненулевое число. Это число и будет наибольшим общим делителем).
Использовать рекурсивный алгоритм.
 */
int GreaterDivider(int num1, int num2)
{
    if(num1 == 0) return num2;
    else if (num2 == 0) return num1;
    else if(num1>num2) return GreaterDivider(num1-num2, num2);
    else if(num2>num1) return GreaterDivider(num1, num2-num1);
}
int main()
{
    int divider = GreaterDivider(12, 36);
    cout << "Greater Divider: " << divider << endl;
}