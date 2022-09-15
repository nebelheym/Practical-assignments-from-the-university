#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
14. Даны действительные числа а, b.
Получить u=min(a,b), v=min(ab,a+b), min(u+v2, 3.14)
*/
double min(double val1, double val2)
{
    if (val1 > val2) return val1;
    else return val2;
}
int main()
{
    double a, b;
    cout << "Enter a and b:" << endl;
    cin >> a >> b;
    double u = min(a, b);
    double v = min(a * b, a + b);
    cout << "u = " << u << endl;
    cout << "v = " << v << endl;
    cout << "min(u+v2, 3.14) =  " << min(u + v * 2, 3.14);
    return 0;
}