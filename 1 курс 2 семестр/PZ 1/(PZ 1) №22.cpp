#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
22. Даны три целые матрицы размером 9х4. 
Напечатать ту из них, где больше ненулевых элементов (если
таких матриц несколько, напечатать их все).
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
int NotNullMatrix(int** matrix, int sizeI, int sizeJ)
{
    int count = 0;
    for (int i = 0; i < sizeI; i++)
        for (int j = 0; j < sizeJ; j++)
            if (matrix[i][j] != 0)
                count++;
    return count;
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
    int sizeI = 9, sizeJ = 4;
    int** A = MatrixCreate(sizeI, sizeJ);
    int** B = MatrixCreate(sizeI, sizeJ);
    int** C = MatrixCreate(sizeI, sizeJ);
    int CountA = NotNullMatrix(A, sizeI, sizeJ);
    int CountB = NotNullMatrix(B, sizeI, sizeJ);
    int CountC = NotNullMatrix(C, sizeI, sizeJ);
    if (CountA > CountB && CountA > CountC) ShowMatrix(A, sizeI, sizeJ);
    else if (CountB > CountA && CountB > CountC) ShowMatrix(B, sizeI, sizeJ);
    else ShowMatrix(C, sizeI, sizeJ);
    return 0;
}