#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x[100];
    x[0] = 1;
    x[1] = 1;
    x[2] = 1;
    double s;
    s = x[0]/2 + x[1]/(2*2) + x[2]/(pow(2, 3));
    for(int i = 3; i<100; i++)
    {
        //cout << "i = " <<  i << endl;
        x[i] = x[i-1]+x[i-3];
        //cout << "x = " << x[i] << endl;
        s += x[i]/pow(2, i);
        //cout << "s = " <<  s << endl;
    }
    cout << s;
    return 0;
}
