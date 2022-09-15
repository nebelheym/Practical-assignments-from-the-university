#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    double t = 0, a[n], x;
    n += 1;
    cout << "Enter x:" << endl;
    cin >> x;
    for(int i = 0; i<n-1; i++)
    {
        cout << "Enter a" << i << ":" << endl;
        cin >> a[i];
    }
    for(int k = 0; k<n; k++)
    {
        t += a[k]*pow(x, n-1);
    }
    cout << "t = " << t;
    return 0;
}