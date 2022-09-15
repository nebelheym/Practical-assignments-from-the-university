#include <iostream>
using namespace std;

int main()
{
    double a, V, Slat;

    cout << "Enter the size of the edge of the cube:" << endl;
    cin >> a;

    V = a * a * a;
    Slat = 4 * a * a;

    cout << "The volume of the cube is: " << V << endl;
    cout << "The lateral surface area of the cube is: " << Slat << endl;

    return 0;
}