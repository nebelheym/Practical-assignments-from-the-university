#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x, y = 0;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter n: " << endl;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        y += (x + cos(i*x))/pow(2, i);
    }
    cout << "y = " << y;
    return 0;
}