#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
8. Составить программу для вычисления математического ожидания mx и дисперсии Dx для моментов
появления случайных событий t1, t2, …, t200 и интервалов между ними. Для вычисления mx и Dx
, использовать функцию без параметров.
*/
//Нашёл в интернете такие формулы Мат.Ожидание = x(i)/n, Дисперсия = sgrt((x(i)-M)^2/(N-1)).
double* tInit(int size)
{
    double* t = new double[size];
    for (int i = 0; i < size; i++)
        t[i] = rand() % 100;
    return t;
}
void ExpectedValueAndDispersion()
{
    int size = 200;
    double* t = tInit(size);
    for (int i = 0; i < size; i++)
        cout << setw(2) << t[i] << " ";
    double mx = 0;
    for (int i = 0; i < size; i++)
        mx += t[i];
    mx /= size;
    double Dx = 0;
    for (int i = 0; i < size; i++)
        Dx += ((t[i] - mx) * (t[i] - mx))/(size - 1);
    Dx = sqrt(Dx);
    cout << endl << "Expected value = " << mx << endl;
    cout << "Dispersion = " << Dx << endl;
}
int main()
{
    ExpectedValueAndDispersion();
    return 0;
}