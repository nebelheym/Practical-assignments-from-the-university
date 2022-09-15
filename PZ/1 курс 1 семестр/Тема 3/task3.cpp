#include <iostream>
using namespace std;

int main() {
    int index = 1;
    bool a = true;
    int n;
    cin >> n;
    long double u[n];
    u[0] = 0;
    u[1] = 1;
    while(a)
    {
        ++index;
        u[index] = u[index-1] + u[index-2];
        // << u[index]<<endl;
        if(index == n)
        {
            cout << u[n];
            a = false;
        }
    }
    return 0;
}