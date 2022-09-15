#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
6. Разработать функцию, которая находит наименьшее общее кратное двух натуральных чисел,
вводимых с клавиатуры (НОК(a,b)=(a*b)/НОД(a,b)). НОД(a,b) – наибольший общий делитель; найти с
помощью алгоритма Евклида (Большее из чисел заменяется разностью этих чисел. Этот процесс
повторяется до тех пор, пока не останется одно ненулевое число. Это число и будет наибольшим общим
делителем). Объявить указатель на функцию, определяющую НОК. Вызвать функцию через этот указатель
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
    int (*Greater)(int, int) = &GreaterDivider;
    cout << "MyPow: " << Greater(15, 5) << endl;
}