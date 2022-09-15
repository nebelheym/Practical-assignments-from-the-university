#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x, y, c, d;
    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;
    c = sqrt(x*x+y*y);
    if(c>=4 && x<4 && y<4 && x>-4 && y>-4)
        cout << "The point with coordinates " << x << ":" << y << " lies in the shaded area";
    else
        cout << "Point with coordinates " << x << ":" << y << " does not lie in the shaded area";
    return 0;
}