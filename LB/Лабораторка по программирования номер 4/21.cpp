#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int i = 2, n = 10;
    long double a[11];
    a[1] = 1;

    for(;i <= n;i++)
    {
        a[i] = pow(a[i-1],2) + 1;
        cout << a[i] << endl;
    }

    return 0;
}
