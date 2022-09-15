#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int i=1, n = 50, a = 3, b = 2, k;

    for(;i <= n;i++)
    {
        k = pow(i,3) - 17*i*pow(n,2) + pow(n,3);
        if (k%a == 0 && k%b != 0) cout << k << endl;
    }

    return 0;
}
