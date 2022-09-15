#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
17. Даны целые массивы А(7), В(6), С(8). 
Определить, в каком массиве число элементов, значения которых
не превышают значение их последнего элемента, является наибольшим.
*/
// Программа всегда будет выдавать массив А, потому что элементы вводятся рандомно,
// при вводе вручую результат будет другим.
int* ArrCreate(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 11;
    return arr;
}
int ValueCount(int* arr, int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        if (arr[i] < arr[size - 1])
            count++;
    return count;
}
int main()
{
    int* A = ArrCreate(7);
    int* B = ArrCreate(6);
    int* C = ArrCreate(8);
    int ACount = ValueCount(A, 7);
    int BCount = ValueCount(B, 6);
    int CCount = ValueCount(C, 8);
    if (ACount > BCount && ACount > CCount) cout << "A" << endl;
    else if (BCount > ACount && BCount > CCount) cout << "B" << endl;
    else cout << "C" << endl;
    return 0;
}