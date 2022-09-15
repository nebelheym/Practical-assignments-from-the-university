#include <iostream>
using namespace std;
int main() {
    double x, y, a, b, f = 1, k = 1, l = 1;
    cin >> x;
    for(int i = 0; i<=5; i++)
    {
        f *= 2;
        a = (x - f);
        k *= a;
        b = (x - f - 1);
        l *= b;
        y = k/l;
    }
    cout << y;
}
