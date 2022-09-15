#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, e, z = 0, fact = 1;
    cout << "Enter x: " << endl;
    cin >> x;
    cout << "Enter e: " << endl;
    cin >> e;
    z = 1;
    int i = 1, k = 1;
    do{
        k *= 2;
        fact *= (fact + 1) * (fact + 2);
        y = pow(x, k)/fact;
        if(i%2 == 0)
            z -= y;
        else
            z += y;
        i++;
        cout << "y = " << y << endl;
    }while(y > e);
    cout << "z = " << z;
    return 0;
}