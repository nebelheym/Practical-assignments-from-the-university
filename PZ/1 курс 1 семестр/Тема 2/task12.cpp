#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter a:" << endl;
    cin >> a;
    cout << "Enter b:" << endl;
    cin >> b;
    cout << "Enter c:" << endl;
    cin >> c;
    if((a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c==b*b+a*a))
    {
        cout << "This is a right triangle";
    }
    else
    {
    cout << "This is either not a right triangle or not a triangle at all";
    }
    return 0;
}