#include <iostream>
using namespace std;
int main() {
    int n, res;
    cout << "Enter array size:" << endl;
    cin >> n;
    double x[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter x" << i << ": " << endl;
        cin >> x[i];
    }
    res = (x[0] + x[1] + 2*x[n-1])*(x[1]+x[3]+2*x[n-2])*(x[n-2]+x[n-1]+2*x[1]);
    cout << "Result = " << res;
    return 0;
}