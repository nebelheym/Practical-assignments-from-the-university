#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    double a = 20, b = 30, n = 10, h, F, sum = 0, result;
    int i=1;
    h = (b - a)/ n;
    for(;i <= n;i++)
    {
        F = (a + (i - 0.5)*h)/(1 + pow(a + (i-0.5)*h,2));
        sum += F;
    }
    result = sum * h;
    cout << result;

    return 0;
}
