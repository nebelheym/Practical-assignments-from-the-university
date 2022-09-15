#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    double result = 1, a = 25;

    for(;n <= 15;n++)
    {
        result *= a+n+1;
    }
    cout << result;

    return 0;
}
