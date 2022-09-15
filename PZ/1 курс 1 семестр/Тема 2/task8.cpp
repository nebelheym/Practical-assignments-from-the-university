#include <iostream>
using namespace std;

int main() {

    int k, m;
    double x, y, z;

    cout << "Enter k:" << endl;
    cin >> k;
    cout << "Enter m:" << endl;
    cin >> m;
    cout << "Enter x:" << endl;
    cin >> x;
    cout << "Enter y:" << endl;
    cin >> y;
    cout << "Enter z:" << endl;
    cin >> z;

    if(k<m)
    {
        cout << "x = " << fabs(x) << "\ny = " << y-0.5 << "\nz = " << z-0.5;
    }
    else if(k==m)
    {
        cout << "x = " << x-0.5 << "\ny = " << fabs(y) << "\nz = " << z-0.5;
    }
    else
    {
        cout << "x = " << x-0.5 << "\ny = " << y-0.5 << "\nz = " << fabs(z);
    }
    return 0;
}