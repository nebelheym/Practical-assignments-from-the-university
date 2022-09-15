#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
8. Даны функции:
Напишите функцию sort() для сортировки числового массива. Для сравнения элементов массива в ней
должна быть вызвана одна из приведенных выше функций. Чтобы поменять элементы массива местами –
вызывать функцию swap(). Передавать в функцию sort() в качестве параметров массив для сортировки, его
размер, указатель на функцию сравнения и указатель на функцию swap().
 */
void swap(int& left, int& right)
{
// поменять значения аргументов
    int buffer = left;
    left = right;
    right = buffer;
}
// 2 функции сравнения:
bool compare_less(int left, int right)
{
    if (left<right)
        return true;
    else
        return false;
}
bool compare_greater(int left, int right)
{
    if (left>right)
        return true;
    else
        return false;
}
int* ArrCreate()
{
    int size;
    cout << "Enter size of array:" << endl;
    cin >> size;
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Enter Array[" << i << "]:" << endl;
        cin >> arr[i];
    }
    return arr;
}
void SortFoo(int* arr, bool (*method)(int, int), void (*sort)(int&, int&))
{
    for(int i = 0; arr[i]; i++)
        for(int j = i + 1; arr[j]; j++)
            if(method(arr[i], arr[j]))
                sort(arr[i], arr[j]);
}
void ShowArr(int* arr)
{
    for(int i = 0; arr[i]; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int* arr = ArrCreate();
    ShowArr(arr);
    SortFoo(arr, compare_greater, swap);
    ShowArr(arr);
}