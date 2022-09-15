#include <iostream>
#include <cmath>
using namespace std;

int factorial(int i)
{
    if (i==0) return 1;
    else return i*factorial(i-1);
}

int main() {
    int n, y, i = 0;
    cin >> n;
    bool condition = true;
    while(condition)
    {
        i++;
        //cout << "i = " << i << endl;
        //cout << "factorial = " << factorial(i) << endl;
        y += factorial(i);
        //cout << "y = " << y << endl;
        if(n == i)
        {
            cout << y;
            condition = false;
        }
    }
    return 0;
}
