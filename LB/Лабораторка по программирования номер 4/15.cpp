#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
     double x = 5, result = 0;

    for(;n <= 15;n++)
    {
        result += pow(x,n) + pow(cos(x),n+1)/n;
    }
    cout << result;

    return 0;
}
