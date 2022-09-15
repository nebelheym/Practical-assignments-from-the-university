#include <iostream>
#include<string.h>
#include <conio.h>
#include <windows.h>
using namespace std;
/*
Задание 2.4. 
Транспонировать матрицу. 
Выполнить для целой и символьной матриц. 
Для вводавывода матриц и транспонирования использовать шаблоны функции.
*/
template <typename t>
t** MatrixCreate(int sizeI, int sizeJ)
{
    t** matrix = new t * [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new t[sizeJ];
    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++)
        {
            cout << "Enter Matrix[" << i << "][" << j << "]:" << endl;
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
template <typename t>
void TransposeMatrix(t** matrix, int sizeI, int sizeJ)
{
    int temp;
    for (int i = 0; i < sizeI; ++i)
    {
        for (int j = i; j < sizeJ; ++j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
template <typename t>
void ShowMatrix(t** matrix, int sizeI, int sizeJ)
{
    for (int i = 0; i < sizeI; ++i)
    {
        for (int j = 0; j < sizeJ; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int size = 2;
    int** IntMatrix = MatrixCreate<int>(size, size);
    char** CharMatrix = MatrixCreate<char>(size, size);
    TransposeMatrix(IntMatrix, size, size);
    TransposeMatrix(CharMatrix, size, size);
    ShowMatrix(IntMatrix, size, size);
    ShowMatrix(CharMatrix, size, size);
    return 0;
}