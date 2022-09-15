#include <iostream>
using namespace std;
int main() {
    const int n = 5;
    double x[n], y, k = n+1;
    for(int i = 0; i<n; i++)
    {
        cout << "Enter x" << i << ": " << endl;
        cin >> x[i];
    }
    cout << "Enter y:" << endl;
    cin >> y;
    for(int i = 0; i<n; i++)
    {
        if(x[i] == y)
        {
            k = i;
            break;
        }
    }
    cout << "k = " << k;
    return 0;
}
