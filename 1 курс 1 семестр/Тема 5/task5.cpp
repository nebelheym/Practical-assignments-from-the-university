#include <iostream>
using namespace std;
int main() {
    int n, k = 1, num = 0;
    cout << "Enter array size:" << endl;
    cin >> n;
    double a[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i << ": " << endl;
        cin >> a[i];
    }
    for(int i = 0; i<n; i++)
    {
        if(a[k]<(a[k-1]+a[k+1])/2)
            num++;
        k++;
    }
    cout << "Num = " << num;
    return 0;
}