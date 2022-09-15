#include <iostream>
using namespace std;
int main() {
    const int k = 5;
    int a[k], b[k], n = 0;
    bool flag;
    for(int i = 0; i<k; i++)
    {
        cout << "Enter a" << i << ":" << endl;
        cin >> a[i];
    }
    b[0] = a[0];
    for(int i = 0; i<k; i++)
    {
        flag = false;
            for(int j = 1; j<n; j++)
            {
                if(a[i] == b[j])
                    flag = true;
            }
        if(flag != true)
            b[n++] = a[i];
    }
    for(int i = 0; i<n; i++)
        cout << "b" << i << ": " << b[i] << endl;
    cout << "number = " << n;
    return 0;
}
