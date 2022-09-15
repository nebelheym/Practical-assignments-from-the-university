#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
int* inputArr()
{
    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 - 50;
    }
    return arr;
}
void averageArr()
{
    int* arr = inputArr();
    float average = 0;
    for (int i = 0; i < sizeof(arr); i++)
    {
        if(arr[i] > 0)
            average += arr[i];
    }
    average /= sizeof(arr);
    cout << "Average:\t" << average << endl;
}
int main()
{
    for (int i = 0; i < 3; i++)
        averageArr();
    return 0;
}