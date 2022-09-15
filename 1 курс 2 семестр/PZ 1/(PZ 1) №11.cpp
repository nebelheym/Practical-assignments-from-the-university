#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
11. Даны натуральные числа n, m, целые числа а1, …, аn, b1, …, bm, с1, …, с30.
Получить...
*/
int* ArrCreate(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 11; // Если поставить + 10 и ниже, то всегда вызывается else в 35 строчке
    return arr;
}
int min(int val, int* arr)
{
    int min = arr[0];
    for (int i = 1; i < val; i++)
        if (min > arr[i])
            min = arr[i];
    return min;
}
int main()
{
    unsigned int n, m;
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Enter m:" << endl;
    cin >> m;
    int* a = ArrCreate(n);
    int* b = ArrCreate(m);
    int* c = ArrCreate(30);
    if (abs(min(n, a)) > 10) cout << "if "  << min(m, b) + min(30, c);
    else cout << "else " << 1 + pow(min(30, c[0]), 2);
    return 0;
}