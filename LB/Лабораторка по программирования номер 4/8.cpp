#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    double sum = 0;

    for(;n <= 15;n++)
    {
        sum += n * (n + 1) * 2 * n;
    }
    cout << sum;

    return 0;
}
