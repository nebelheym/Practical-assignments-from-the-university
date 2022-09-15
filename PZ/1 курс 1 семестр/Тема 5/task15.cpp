#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter a" << i << ": " << endl;
        cin >> a[i];
    }
    for(int i = 0; i<n; i++)
    {
        if(a[i+1]%2 == 0 && a[i]%2 != 0)
        {
            cout << "a>0:" << endl;
            for(int i = n; i>0; i--)
            {
                if(a[i] > 0)
                    cout << "a" << i << ": " << a[i] << endl;
            }
            break;
        }
        else
        {
            cout << "a<0:" << endl;
            for(int i = n; i>0; i--)
            {
                if(a[i] < 0)
                    cout << "a" << i << ": " << a[i] << endl;
            }
            break;
        }
    }
    return 0;
}
