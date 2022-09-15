#include <iostream>
using namespace std;

int main() {
    double x, y;
    for(x = -10; x<=10; x+=2)
    {
        if(fabs(x)<5)
        {
            double a = pow(x, 2) + 0.75;
            y = log(a);
            cout << "x = " << x << " ; " <<"y = " << y << endl;
        }
        else if(fabs(x)>5)
        {
            y = pow(x, 4)+2*pow(x, 2)*sin(x);
            cout << "x = " << x << " ; " <<"y = " << y << endl;
        }
    }
    return 0;
}