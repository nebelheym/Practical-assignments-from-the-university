#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double y = 0;
    for(int i = 99; i>=3; i -= 3)
    {
        y = sqrt(y+i);
        //cout << "y = " << y << endl;
        //cout << "i = " << i << endl;
    }
    cout << "Y = " << y << endl;
    return 0;
}