#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, e, k = 0;
    cout << "Enter a:" << endl;
    cin >> a;
    cout << "Enter b:" << endl;
    cin >> b;
    cout << "Enter e:" << endl;
    cin >> e;
    double x, y, x1, y1;
    x = a;
    y = b;
    bool flag = true;
    while(flag)
    {
        k++;
        x1 = (1.0/2)*(x+y);
        //cout << "x1 = " << x1 << " ";
        y1 = sqrt(x*y);
        //cout << "y1 = " << y1 << " ";
        x = x1;
        y = y1;
        //cout << "x1-y1 = " << x1-y1 << endl;
        if((x1-y1)<e)
            flag = false;
    }
    cout << "xk = " << x1;
    return 0;
}