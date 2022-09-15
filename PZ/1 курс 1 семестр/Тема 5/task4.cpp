#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter array size:" << endl;
    cin >> n;
    double a[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i << ": " << endl;
        cin >> a[i];
    }
    int aMin = a[0], j;
    for(int i = 0; i<n; i++)
    {
        if(aMin > a[i])
        {
            aMin = a[i];
            //cout << "aMin = " << aMin << endl;
            j = i;
        }
    }
    //cout << "j = " << j << endl;
    for(int i = j - 1; i>=0; i--)
    {
        //cout << "i = " << i << endl;
        //cout << "a" << i << " = " << a[i] << endl;
        a[i] = a[i] * aMin;
    }
    for(int i = 0; i<n; i++)
        cout << "a" << i << " = " << a[i] << endl;
    return 0;
}