#include <iostream>
using namespace std;

int main() {

    double x, y;

    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;

    if(x>0 && y>0)
    {
        cout << "Quadrant: 1";
    }
    else if(x<0 && y>0)
    {
        cout << "Quadrant: 2";
    }
    else if(x<0 && y<0)
    {
        cout << "Quadrant: 3";
    }
    else if(x>0 && y<0)
    {
        cout << "Quadrant: 4";
    }
    else if(x == 0 && y != 0)
    {
        cout << "Axis: x";
    }
    else if(x != 0 && y == 0)
    {
        cout << "Axis: y";
    }
    else
    {
        cout << "The point is at coordinate 0:0";
    }

    return 0;
}