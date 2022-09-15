#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int i=1;
    double S = 0, p=3.14;

    for(;i <= 10;i++)
    {
        S += sin (p/i);
    }
    cout << S;

    return 0;
}
