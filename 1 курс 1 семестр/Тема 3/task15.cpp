#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x = 1;
    cin >> n;
    for(int i = 0; i<=n; i++)
    {
        x += 0.1*n;
        cout << x << endl;
        double y = (x*x-3*x+2)/(sqrt(2*pow(x,3)-1));
        cout << "y = " << y << endl;
    }
    return 0;
}