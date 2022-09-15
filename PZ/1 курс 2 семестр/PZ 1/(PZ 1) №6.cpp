#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
void xFunc(int& x1, int& x2)
{
    int a, b;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    float D = b * b - 4 * a * 1.5f;
    if (D < 0)
    {
        x1 = 0;
        x2 = 0;
    }
    else if (D = 0)
    {
        x1 = -b / (2 * a);
        x2 = x1;
    }
    else
    {
        x1 = ( - b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
    }
}
void yFunc(int& y1, int& y2)
{
    int a, b, c;
    cout << "Enter a: " << endl;
    cin >> a;
    cout << "Enter b: " << endl;
    cin >> b;
    cout << "Enter c: " << endl;
    cin >> c;
    float D = b * b - 4 * a * c;
    if (D < 0)
    {
        y1 = 0;
        y2 = 0;
    }
    else if (D = 0)
    {
        y1 = -b / (2 * a);
        y2 = y1;
    }
    else
    {
        y1 = (-b + sqrt(D)) / (2 * a);
        y2 = (-b - sqrt(D)) / (2 * a);
    }
}
void func()
{
    int x1, x2, y1, y2;
    xFunc(x1, x2);
    yFunc(y1, y2);
    float u = exp(x1 + y1) - exp(x2 - y2);
    cout << "u = \t" << u << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    func();
    system("pause");
    return 0;
}