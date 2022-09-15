#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
2. Создать структуру Треугольник с тремя элементами a, b, c – длины 3-х сторон.
Найти, у какого из N заданных треугольников площадь наибольшая?
*/
struct Triangle
{
    int a;
    int b;
    int c;
    int square;
};
int main()
{
    int size;
    cout << "Enter count of Triangle's:" << endl;
    cin >> size;
    int max = -1; // Потому что отрицательной площадь всё равно не будет
    int maxI = 0;
    Triangle* arr = new Triangle[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " a, b , c;" << endl;
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
        int p = (arr[i].a + arr[i].b + arr[i].c) / 2;
        arr[i].square = sqrt(p * (p - arr[i].a) * (p - arr[i].b) * (p - arr[i].c));
        if (max < arr[i].square)
        {
            max = arr[i].square;
            maxI = i + 1;
        }
    }
    cout << "Max square is " << max << " at the triangle " << maxI;
    return 0;
}