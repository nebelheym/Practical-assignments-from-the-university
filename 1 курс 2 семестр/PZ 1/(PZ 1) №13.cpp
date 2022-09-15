#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
13. По заданным 20-элементным целым массивам x и y вычислить
*/
int* ArrCreate(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10;
    return arr;
}
int Sum1(int size, int* arr1, int* arr2)
{
    int sum = 0;
    for (int i = 1; i < size; i++)
        sum += arr1[i] * arr2[i];
    return sum;
}
int Sum2(int size, int* arr)
{
    int sum = 0;
    for (int i = 1; i < size; i++)
        sum += arr[i] * arr[i];
    return sum;
}
int Sum3(int size, int* arr)
{
    int sum = 0;
    for (int i = 10; i < size; i++)
        sum += arr[i] * arr[i];
    return sum;
}
int main()
{
    int size = 20;
    int* x = ArrCreate(size);
    int* y = ArrCreate(size);
    int u;
    if (Sum1(15, x, y) > 0) u = Sum2(size, x);
    else u = Sum3(20, y);
    cout << "u = " << u;
    return 0;
}