#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    double a[n], k, temp;
    cout << "Enter k:" << endl;
    cin >> k;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i <<":" << endl;
        cin >> a[i];
    }
    for(int i = 0; i<k; i++)
    {
        temp=a[n-1];
        for (int i=n-1; i>=1; i--)
            a[i] = a[i-1];
        a[0]=temp;
    }

    for(int i = 0; i<n; i++)
        cout << "a" << i << ": " << a[i] << endl;
    return 0;
}