#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
21. Даны две матрицы А(6,4), В(3,5). 
Напечатать ту матрицу, у которой произведение максимального и
минимального элементов наибольшее
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
int ProductMatrix(int** matrix, int sizeI, int sizeJ)
{
    int min = matrix[0][0];
    int max = matrix[0][0];
    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++)
        {
            if (min > matrix[i][j])
                min = matrix[i][j];
            if (max < matrix[i][j])
                max = matrix[i][j];
        }
    }
    int product = min * max;
    return product;
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
int main()
{
    int** a = MatrixCreate(6, 4);
    int** b = MatrixCreate(3, 5);
    int ProductA = ProductMatrix(a, 6, 4);
    int ProductB = ProductMatrix(b, 3, 5);
    if (ProductA > ProductB) ShowMatrix(a, 6, 4);
    else ShowMatrix(b, 3, 5);
    return 0;
}