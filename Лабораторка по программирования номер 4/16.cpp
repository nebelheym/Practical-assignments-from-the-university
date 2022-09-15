#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    double x = 10, result = 0;

    for(;n <= 15;n++)
    {
        result += pow(sin(x),2);
    }
    cout << result;

    return 0;
}
