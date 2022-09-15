#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    double sum = 0, a=50, fact = 1;
    int n = 1;

    for(;n <= 10;n++)
    {
        fact *= n;
        sum += n%2 == 0? a/fact:-1*a/fact;
        cout << sum << endl;
    }
    cout << sum;

    return 0;
}
