#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
24. Даны две матрицы С(5,7) и D(6,8). 
Для каждой матрицы сформировать массивы из произведений
отрицательных элементов каждого столбца; 
если их в столбце нет, результат должен быть равен 0.
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
    int* arr = new int[sizeI];
    int product;
    bool flag;
    for (int i = 0; i < sizeI; i++)
    {
        product = 1;
        flag = false;
        for (int j = 0; j < sizeJ; j++)
        {
            if (matrix[i][j] < 0)
            {
                flag = true;
                product *= matrix[i][j];
            }
        }
        if (flag) arr[i] = product;
        else arr[i] = 0;
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
    for (int i = 0; i < sizeI; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int** C = MatrixCreate(5, 7);
    int** D = MatrixCreate(6, 8);
    ShowMatrix(C, 5, 7);
    ShowMatrix(D, 6, 8);
    int* ProductC = ArrCreate(C, 5, 7);
    int* ProductD = ArrCreate(D, 6, 8);
    ShowArr(ProductC, 5);
    ShowArr(ProductD, 6);
    return 0;
}