#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, z, fact = 1, i = 1;
    cout << "Enter x: " << endl;
    cin >> x;
    z = x;
    y = z;
    while(z > ((exp(x) - exp(-x))/2)*x)
    {
        i++;
        fact *= i;
        i++;
        fact *= i;
        z = pow(x, 3)/fact;
        y += z;
    }
    y += z;
    cout << "shx = " << y;
    return 0;
}