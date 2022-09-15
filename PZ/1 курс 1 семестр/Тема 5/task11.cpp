#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    int a[n], var = 0;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i <<":" << endl;
        cin >> a[i];
        var += a[i];
    }
    var = var/n;
    a[n-1] = var;
    for(int i = 0; i<n; i++)
        cout << "a" << i << ": " << a[i] << endl;
    return 0;
}