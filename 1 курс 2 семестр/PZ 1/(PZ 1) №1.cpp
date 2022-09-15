#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
//1. Составить программу для вычисления значений функции
float firstFunc(float s, float z, float q, float t)
{
    float a = (sqrt(s * pow(z, 3) + q * z * z + t * z + t)) / (1 + exp(s * pow(z, 3) + z - 1));
    return a;
}
float secondFunc(float t, float z, float r, float alpha, float beta)
{
    float b = (t * t * sin(alpha) + t * cos(beta) + 3.5) / (z * z - 2 * r - t);
    return b;
}
int main()
{
    float a = firstFunc(5.0f, -4.0f, 111.2f, 12.3f);
    float b = secondFunc(5.5f, 18.2f, -123.0f, 30.0f, 45.0f);
    cout << "a: " << a << "\t b: " << b;
    return 0;
}