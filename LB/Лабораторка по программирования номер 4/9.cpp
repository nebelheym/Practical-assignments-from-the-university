#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    double dob = 1, n = 1;

    for(;n <= 15;n++)
    {
        dob *= (2*n-1)/n;
    }
    cout << dob;

    return 0;
}
