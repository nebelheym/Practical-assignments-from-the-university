#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
int* input(int &size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Arr[" << i << "]:\t" << endl;
        cin >> arr[i];
    }
    return arr;
}
void maxMin(int& min, int& max)
{
    int size;
    cout << "Enter size of array:\t" << endl;
    cin >> size;
    int* arr = input(size);
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
}
void func()
{
    int minX, maxX, minY, maxY;
    maxMin(minX, maxX);
    maxMin(minY, maxY);
    float z = (exp(maxX) - exp(maxY)) / (sqrt(minX * minY));
    cout << "z =\t" << z << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    func();
    system("pause");
    return 0;
}