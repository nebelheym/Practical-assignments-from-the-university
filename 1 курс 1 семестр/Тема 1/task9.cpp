#include <iostream>
using namespace std;
int main()
{
    int value, a, b, c, d, e, sum;
    cin >> value;
    a = value / 10000;
    b = (value - a * 10000) / 1000;
    c = (value - a * 10000 - b * 1000) / 100;
    d = (value - a * 10000 - b * 1000 - c * 100) / 10;
    e = (value - a * 10000 - b * 1000 - c * 100 - d * 10);
    sum = a + b + c + d + e;
    cout << sum;
    return 0;
}
