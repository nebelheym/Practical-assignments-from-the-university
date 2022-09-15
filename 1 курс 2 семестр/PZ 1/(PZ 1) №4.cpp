#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
int** input(int &sizeI, int &sizeJ)
{
    cout << "Enter size i:" << endl;
    cin >> sizeI;
    cout << "Enter size j:" << endl;
    cin >> sizeJ;
    int** matrix;
    matrix = new int* [sizeI];
    for (int i = 0; i < sizeI; i++)
        matrix[i] = new int[sizeJ];
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

void geomAverage(int** matrix, int sizeI, int sizeJ)
{
    double geom;
    double* arr = new double[sizeJ];
    for (int i = 0; i < sizeJ; i++)
    {
        geom = 1;
        for (int j = 0; j < sizeI; j++)
        {
            geom *= matrix[j][i];
        }
        geom /= sizeI;
        arr[i] = geom;
    }
    for (int i = 0; i < sizeJ; i++)
    {
        cout << "Arr[" << i << "]:\t" << arr[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int sizeI, sizeJ;
    cout << "Введите размер массива: " << endl;
    int** matrix = input(sizeI, sizeJ); // Функция ввода
    geomAverage(matrix, sizeI, sizeJ); // Функция вывода
    delete[] matrix;
    system("pause");
    return 0;
}