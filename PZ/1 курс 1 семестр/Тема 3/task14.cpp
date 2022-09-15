#include <iostream>
#include <cmath>
using namespace std;

long double fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int main() {
    int n;
    double x, product = 1;
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Enter x:" << endl;
    cin >> x;
    for(double k = 1; k<=n; k++)
    {
        product *= 1+(sin(k*x)/fact(k));
    }
    cout << "Product is: " << product;
    return 0;
}