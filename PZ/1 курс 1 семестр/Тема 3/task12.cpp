#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    double x = 1, y = 1, sum = x/(1+abs(y));
    for(int i = 2; i<=n; i++)
    {
        y = x+y;
        x = 0.3*x;
        sum += x/(1+abs(y));
    }
    cout << "sum is: " << sum;
    return 0;
}