#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    double x, y, radiusMax, radius;
    cout << "Enter x" << endl;
    cin >> x;
    cout << "Enter y" << endl;
    cin >> y;
    radiusMax = sqrt(x*x+y*y);
    for(int i = 2; i<=n; i++)
    {
        cout << "Enter x" << i << ":" << endl;
        cin >> x;
        cout << "Enter y" << i << ":" << endl;
        cin >> y;
        radius = sqrt(x*x+y*y);
        if(radius>radiusMax)
            radiusMax = radius;
        //cout << "Radius is: " << Radius[i] << endl;
    }
    cout << "radiusMax = " << radiusMax;
    return 0;
}