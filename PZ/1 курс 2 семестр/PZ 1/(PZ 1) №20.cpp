#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
20. Даны две матрицы С(5,4) и D(6,5). 
Для каждой матрицы сформировать массивы из сумм положительных
элементов каждой строки; если их в строке нет, результат должен быть равен 0.
*/
int** MatrixCreate(int sizeI, int sizeJ)
{
    int** matrix = new int* [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new int[sizeJ];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            matrix[i][j] = rand() % 100;
    return matrix;
}
int* ArrCreate(int** matrix, int sizeI, int sizeJ)
{
    int* arr = new int[sizeI];
    int sum;
    for (int i = 0; i < sizeI; i++)
    {
        sum = 0;
        for (int j = 0; j < sizeJ; j++)
            sum += matrix[i][j];
        arr[i] = sum;
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
void ShowArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int** a = MatrixCreate(5, 4);
    int** b = MatrixCreate(6, 5);
    ShowMatrix(a, 5, 4);
    ShowMatrix(b, 6, 5);
    int* SumA = ArrCreate(a, 5, 4);
    int* SumB = ArrCreate(b, 6, 5);
    ShowArr(SumA, 5);
    ShowArr(SumB, 6);
    return 0;
}