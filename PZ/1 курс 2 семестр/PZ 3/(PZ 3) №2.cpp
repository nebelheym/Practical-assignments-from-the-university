#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
2. Найти сумму цифр целого числа, вводимого с клавиатуры.
Суммирование должно осуществляться
рекурсивной функцией.
 */
int SumOfNumbers(int value)
{
    if (value < 10) return value;
    else return (value%10)+SumOfNumbers(value/10);
}
int main()
{
    int sum = SumOfNumbers(124);
    cout << "Sum = " << sum;
}