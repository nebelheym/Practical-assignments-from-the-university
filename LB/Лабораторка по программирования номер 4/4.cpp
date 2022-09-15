#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    double n = 15, min = 99999999, a;
    int i=1;

    for(;i <= n;i++)
    {
        a = (i-1)/(i+1) + sin(pow(i-1,3))/(i+1);
        if (a >= 0 && a < min ) min = a;
    }
    cout << min;

    return 0;
}
