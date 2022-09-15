#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
25. Даны две матрицы С(8,6) и D(7,5). 
Для каждой матрицы сформировать массивы из средних
арифметических значений элементов нечетных строк.
*/
int** MatrixCreate(int sizeI, int sizeJ)
{
    int** matrix = new int* [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new int[sizeJ];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            matrix[i][j] = rand() % 100 - 5;
    return matrix;
}
int* ArrCreate(int** matrix, int sizeI, int sizeJ)
{
    int SizeArr;
    if (sizeI % 2 == 0) SizeArr = sizeI/2;
    else SizeArr = sizeI / 2 + 1;
    int* arr = new int[SizeArr];
    int average;
    int count = 0;
    for (int i = 0; i < sizeI; i++)
    {
        average = 0;
        if (i+1 % 2 != 0)
            for (int j = 0; j < sizeJ; j++)
                    average += matrix[i][j];
        arr[count++] = average/sizeJ;
    }
    return arr;
}
void ShowMatrix(int** matrix, int sizeI, int sizeJ)
{
    cout << endl;
    cout << "Matrix:" << endl;
    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void ShowArr(int* arr, int sizeI)
{   
    if (sizeI % 2 == 0) sizeI /= 2;
    else sizeI = sizeI / 2 + 1;
    for (int i = 0; i < sizeI; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int** C = MatrixCreate(8, 6);
    int** D = MatrixCreate(7, 5);
    ShowMatrix(C, 8, 6);
    ShowMatrix(D, 7, 5);
    int* AverageC = ArrCreate(C, 8, 6);
    int* AverageD = ArrCreate(D, 7, 5);
    ShowArr(AverageC, 8);
    ShowArr(AverageD, 7);
    return 0;
}