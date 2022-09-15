#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const int n = 5;
    int a[n], aMax;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i <<":" << endl;
        cin >> a[i];
        if(i == 0)
            aMax = abs(a[i]);
        if(aMax < abs(a[i]))
            aMax = abs(a[i]);
    }
    for(int i = 0; i<n; i++)
        if(abs(a[i]) == aMax)
            a[i] = 1;
        else
            a[i] = 0;
    for(int i = 0; i<n; i++)
        cout << "a" << i << ": " << a[i] << endl;
    return 0;
}