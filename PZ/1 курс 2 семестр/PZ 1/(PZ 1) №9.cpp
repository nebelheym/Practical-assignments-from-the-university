#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
7.	Составить программу для вычисления значения z = x1 + x2 + x3, где
*/
int* ArrCreate(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 - 50;
    return arr;
}
long double fact(int value)
{
    if (value < 0)return 0;
    if (value == 0)return 1;
    else return value * fact(value - 1);
}
long double x1()
{
    long double sum = 0;
    int* arr = ArrCreate(10);
    for (int i = 0; i < 10; i++)
    {
        if (arr[2 * i + 1] != NULL)
            sum += arr[2 * i + 1];
        else break;
    }
    sum = sum / fact(21);
    return sum;
}
long double x2()
{
    long double sum = 0;
    int* arr = ArrCreate(20);
    for (int i = 0; i < 20; i++)
    {
        if (arr[2 * i] != NULL)
            sum += arr[2 * i];
        else break;
    }
    sum = sum / fact(40);
    return sum;
}
double x3()
{
    long double sum = 0;
    int* arr = ArrCreate(40);
    for (int i = 0; i < 40; i++)
    {
        if (arr[2 * i] != NULL)
            sum += arr[2 * i];
        else break;
    }
    sum = sum / fact(41);
    return sum;
}
double z()
{
    long double z = x1() + x2() + x3();
    return z;
}
int main()
{
    cout << z();
    return 0;
}