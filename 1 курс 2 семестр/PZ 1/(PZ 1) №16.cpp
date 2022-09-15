#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
16. По заданным 10-элементным вещественным массивам a, b и c вычислить t...
*/
int* ArrCreate(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 11;
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
int max(int val, int* arr)
{
    int max = arr[0];
    for (int i = 1; i < val; i++)
        if (max < arr[i])
            max = arr[i];
    return max;
}
int main()
{
    int size = 10;
    int* a = ArrCreate(size);
    int* b = ArrCreate(size);
    int* c = ArrCreate(size);
    int t;
    if (min(size, a) > max(size, b))
        t = ((min(size, b) / max(size, a)) + (max(size, c) / min(size, b)));
    else t = max(size, b) + min(size, c);
    cout << "t = " << t;
    return 0;
}