#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double b;
    int n, i = 0;
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Enter b:" << endl;
    cin >> b;
    double a = b, a1;
    bool flag = true;
    while(a1<0)
    {
        i++;
        a1 = a - 1/sqrt(i);
        a = a1;
    }
    cout << "a1 = " << a1;
    return 0;
}