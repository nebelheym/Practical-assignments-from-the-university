#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    long long int i=1, fact = 1;
    long double b, n = 15;

    for(;i <= n;i++)
    {
        fact *= i;
        b = pow(2,i)/fact;
        cout << b << endl;
    }

    return 0;
}
