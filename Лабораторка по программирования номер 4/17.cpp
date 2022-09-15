#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 0;
    double a = 10, result = 1;

    for(;n <= 15;n++)
    {
        result *= a-pow(n,2);
    }
    cout << result;

    return 0;
}
