#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    long long int n = 1;
    double sum = 0,fact = 1;

    for(;n <= 15;n++)
    {
        fact *= n;
        sum += n%2 != 0? -(n+1)/fact:(n+1)/fact;
        cout << sum << endl;
    }

    return 0;
}
