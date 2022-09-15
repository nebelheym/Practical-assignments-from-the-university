#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int i = 1, n = 10, sum = 0, result;

    for(;i <= n;i++)
    {
        result = pow(i,2) - 3*i*pow(n,2) + n;
        if (result % 5 == 0 && result % 3 != 0) sum += result;
    }
    cout << sum;

    return 0;
}
