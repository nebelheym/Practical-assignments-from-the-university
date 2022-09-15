#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    double n = 15, result, max = -99999999;
    int k=1;

    for(;k <= n; k++)
    {
        result = k * exp(pow(sin(k+1),2));
        if (result > max) max = result;
    }
    cout << max;

    return 0;
}
