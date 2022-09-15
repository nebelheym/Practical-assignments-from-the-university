#include <iostream>
using namespace std;
int main()
{
    int x, y, z;
    cin >> x;
    cin >> y;
    cout << "First value of x: " << " " << x << endl;
    cout << "First value of y: " << " " << y << endl;
    z = x;
    x = y;
    y = z;
    cout << "Second value of x: " << " " << x << endl;
    cout << "Second value of y: " << " " << y << endl;
    return 0;
}
