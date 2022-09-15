#include <iostream>
using namespace std;

int main() {
    int n;
    double a = 1, b = 2, c = a/b;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        a = a + 2;
        b = b + 2;
        c = c * (a/b);
    }
    cout << c;
    return 0;
}