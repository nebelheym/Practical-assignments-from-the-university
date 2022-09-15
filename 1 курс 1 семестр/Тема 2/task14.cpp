#include <iostream>
using namespace std;

int main() {
    double x, y, r1, r2, c;
    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;
    cout << "Enter radius 1:" << endl;
    cin >> r1;
    cout << "Enter radius 2:" << endl;
    cin >> r2;
    c = sqrt(x*x+y*y);
    if(r1<r2)
    {
        if(c>r1 && c<r2)
        {
            cout << "The point with coordinates " << x << ":" << y << " lies in the ring";
        }
        else
        {
            cout << "Point with coordinates " << x << ":" << y << " does not lie in the ring";
        }
    } else{
        if(c<r1 && c>r2)
        {
            cout << "The point with coordinates " << x << ":" << y << " lies in the ring";
        }
        else{
            cout << "Point with coordinates " << x << ":" << y << " does not lie in the ring";
        }
    }
    return 0;
}