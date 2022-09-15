#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    double y, x = 3;

    for(;n <= 20;n++)
    {
        y = sin(x - cos(n*x)/x);
        if (y >= 0) cout << y << endl;
    }

    return 0;
}
