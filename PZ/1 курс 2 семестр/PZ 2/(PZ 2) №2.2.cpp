#include <iostream>
#include<string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
/*
Задание 2.2. Найти произведение отрицательных элементов последовательности чисел (используя
подход 1 и 2)
*/
double product1(int k, ...)
{
    int* p = &k;
    double product = 1;
    for (; k != 0; k--)
        if (*(++p) < 0)
            product *= *(p);
    return product;
}
double product2(int k, ...)
{
    int* p = &k;
    double product;
    if (*p < 0) product = *p;
    else product = 1;
    for (int i = 1; *p != 0; i++)
        if (*(++p) < 0)
            product *= *(p);
    return product;
}
int main()
{
    cout << product1(2, -4, 6) << endl;
    cout << product2(4, -1, 0);
    return 0;
}