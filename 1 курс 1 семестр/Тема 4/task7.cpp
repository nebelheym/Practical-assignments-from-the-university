#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a, b, e, fx, fa, fb, x, n = 0;
    cout << "Enter a, b, e:" << endl;
    cin >> a >> b >> e;
    fa = exp(a) - exp(-a) - 2;
    fb = exp(b) - exp(-b) - 2;
    if(fa*fb<0)
    {
        do {
            x = (a+b)/2;
            fx = exp(x) - exp(-x) - 2;
            if(fa*fx<0) b = x;
            else {a = x, fa = fx;}
            n++;
        }while(abs(b-a)>= e);
            cout << "root = " << x;
    }
    else cout << "no roots";
    return 0;
}
