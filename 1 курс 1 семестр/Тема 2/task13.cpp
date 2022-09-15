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
    if(a == b && b == c)
    {
        cout << "This is an equilateral triangle (3)";
    }else if((a+b > c && a == b) || (a+c > b && a == c) || (b+c > a && b == c))
    {
        cout << "This is an isosceles triangle (2)";
    }
    else if((a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c==b*b+a*a))
    {
        cout << "This is a right triangle (1)";
    }
    else if(a!=b && a!=c && b!=c && a+b>c && a+c>b && b+c>a)
    {
        cout << "It's a versatile triangle (1)";
    }
    else
    {
        cout << "This is not a triangle (0)";
    }
    return 0;
}