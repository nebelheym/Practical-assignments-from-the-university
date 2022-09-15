#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
18. Даны два вещественных 20-элементных массива. 
Переписать в новые массивы элементы исходных,
целая часть которых кратна 3.
*/
double* ArrCreate(int size)
{
    double* arr = new double[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 11;
    return arr;
}
double* NewArrCreate(double* arr, int size, int& count)
{
    double* NewArr = new double[size];
    count = 0;
    for (int i = 0; i < size; i++)
        if (int(arr[i]) % 3 == 0)
            NewArr[count++] = arr[i];
    return NewArr;
}
void ArrShow(double* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int size = 20;
    double* X = ArrCreate(size);
    double* Y = ArrCreate(size);
    int count;
    double* NewX = NewArrCreate(X, size, count);
    ArrShow(NewX, count);
    double* NewY = NewArrCreate(Y, size, count);
    ArrShow(NewY, count);
    return 0;
}