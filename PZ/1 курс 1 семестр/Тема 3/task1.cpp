#include <iostream>
using namespace std;

int main() {
    double y, a = 0, b = 0, c;
    for (double x = 2; x <6.1; x+=0.2)
    {
        y=tan(x);
        cout << "x = "<< x << "; y = " << y << endl;
        if(y>0.2 && y<0.8)
        {
            a += y;
            b += 1;
        }
    }
    c = a/b;
    cout << "Arithmetic mean of function values greater than 0.2 and less than 0.8: " << c;
    return 0;
}