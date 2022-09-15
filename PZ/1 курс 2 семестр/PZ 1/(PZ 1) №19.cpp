#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
19. Даны натуральные числа n, m, вещественные матрицы а(n,m) и b(n,m).
Поменять местами максимальные
элементы матриц а и b.
(Считать, что в каждой матрице только один максимальный элемент).
*/
double** MatrixCreate(int sizeI, int sizeJ)
{
    double** matrix = new double* [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new double[sizeJ];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            cin >> matrix[i][j];
    return matrix;
}
int* Max(double** matrix, int sizeI, int sizeJ, double& max)
{
    int* arr = new int[2];
    arr[0] = 0;
    arr[1] = 0;
    max = matrix[0][0];
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            if (max < matrix[i][j])
            {
                max = matrix[i][j];
                arr[0] = i;
                arr[1] = j;
            }
    cout << "Max:\t" << max << endl;
    cout << "PosI:\t" << arr[0] << endl;
    cout << "PosJ:\t" << arr[1] << endl;
    return arr;
}
void ShowMatrix(double** matrix, int sizeI, int sizeJ)
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
    unsigned int n, m;
    cout << "Enter n and m:" << endl;
    cin >> n >> m;
    double** a = MatrixCreate(n, m);
    double** b = MatrixCreate(n, m);
    ShowMatrix(a, n, m);
    ShowMatrix(b, n, m);
    double MaxA;
    int* PosA = Max(a, n, m, MaxA);
    double MaxB;
    int* PosB = Max(b, n, m, MaxB);
    a[PosA[0]][PosA[1]] = MaxB;
    b[PosB[0]][PosB[1]] = MaxA;
    ShowMatrix(a, n, m);
    ShowMatrix(b, n, m);
    return 0;
}