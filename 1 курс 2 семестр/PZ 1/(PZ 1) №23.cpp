#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
23. Даны три вещественные матрицы А(5,6), В(7,4), С(4,5). 
Вычислить произведение минимальных
элементов матриц.
*/
int** MatrixCreate(int sizeI, int sizeJ)
{
    int** matrix = new int* [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new int[sizeJ];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            matrix[i][j] = rand() % 100 + 1;
    return matrix;
}
int MinMatrix(int** matrix, int sizeI, int sizeJ)
{
    int min = matrix[0][0];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            if (min > matrix[i][j])
                min = matrix[i][j];
    return min;
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
    int** A = MatrixCreate(5, 6);
    int** B = MatrixCreate(7, 4);
    int** C = MatrixCreate(4, 5);
    int MinA = MinMatrix(A, 5, 6);
    int MinB = MinMatrix(B, 7, 4);
    int MinC = MinMatrix(C, 4, 5);
    cout << "Product:\t" << MinA * MinB * MinC << endl;
    return 0;
}