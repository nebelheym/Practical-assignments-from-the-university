#include <iostream>
using namespace std;

int main() {

    double x, y, z;

    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;

    if(x<0)
    {
        if(x>y)
        {
            z = x;
        }
        else
        {
            z = y;
        }
    }
    else
    {
        if(x<y)
        {
            z = x;
        }
        else
        {
            z = y;
        }
    }

    cout << "z = " << z;

    return 0;
}