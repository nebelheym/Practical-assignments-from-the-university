#include <iostream>
using namespace std;

int main() {
    int n, c = 1;
    double b, result;
    cin >> b;
    cin >> n;
    long double u[n];
    result = b * (b + n);
    bool a = true;
    while(a)
    {
        ++c;
        u[c] = b + c * n;
        result = result * u[c];
        if(c == n)
        {
            a = false;
            cout << result;
        }
    }
    return 0;
}