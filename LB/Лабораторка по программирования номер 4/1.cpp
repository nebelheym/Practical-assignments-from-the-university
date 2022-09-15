#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

   long long int res, n, n1 = 1, k;

    cin >> n;

    k = n;

    for(;;)
    {
        if (n % 2 == 0)
        {
            n1 *= n;
            n -= 2;
            if (n == 2)
            {
                n1 *= n;
                n = k;

                break;
            }
        }
        if (n % 2 != 0)
        {
            n1 *= n;
            n -= 2;
            if (n == 1)
            {
                n1 *= n;
                n = k;
                break;
            }
        }
    }
    res = pow(-1,n+1) * n1;
    cout << res;

    return 0;
}
