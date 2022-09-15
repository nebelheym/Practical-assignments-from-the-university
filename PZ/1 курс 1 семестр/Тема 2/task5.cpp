#include <iostream>
using namespace std;

int main() {

    double feet, kilometers, absolutely;

    cout << "Enter the value of feet:" << endl;
    cin >> feet;
    cout << "Enter the value of kilometers:" << endl;
    cin >> kilometers;

    absolutely = feet * 0.0003048;

    if(absolutely > kilometers)
    {
        cout << "Feet more than kilometers";
    }
    else if(absolutely < kilometers)
    {
        cout << "Kilometers over feet";
    }
    else
    {
        cout << "Feet and kilometers are the same amount";
    }

    return 0;
}