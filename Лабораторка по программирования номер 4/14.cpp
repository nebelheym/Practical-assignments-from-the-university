#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    long double fact = 1, x = 10, dob=1;

    for(;n <= 15;n++)
    {
        fact *= n;
        dob *= fact + n*x;
    }
    cout << dob;

    return 0;
}
