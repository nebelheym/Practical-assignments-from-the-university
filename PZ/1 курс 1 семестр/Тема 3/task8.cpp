#include <iostream>
#include <cmath>
using namespace std;

int factorial(int i)
{
    if (i==0) return 1;
    else return i*factorial(i-1);
}

int main() {
    double x, y;
    cin >> x;
    y = -(pow(x, 3)/factorial(3))+(pow(x, 5)/factorial(5))-(pow(x, 7)/factorial(7))+(pow(x, 9)/factorial(9))-(pow(x, 11)/factorial(11))+(pow(x, 13)/factorial(13));
    cout << y;
}
