#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1, sum = 0;

    for(;n <= 100;n++)
    {
        sum += n;
    }
    cout << sum;

    return 0;
}
