#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int i = 1, fact = 1, n = 15;
    double result = 0, x = 17;

    for(;i <= n;i++)
    {
        fact *= i;
        result += 1.0/fact + x;
    }
    cout << result;

    return 0;
}
