#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double y, x;
    cout << "Enter y:" << endl;
    cin >> y;
    cout << "Enter x:" << endl;
    cin >> x;
    bool flag = true;
    y = sin(x);
    while(flag)
    {
        y = sin(y);
        //cout << "y = " << abs(y) << endl;
        if(abs(y) < 0.01)
            flag = false;
    }
    cout << "y = " << y;
    return 0;
}