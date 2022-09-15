#include <iostream>
#include <cmath>
using namespace std;
int main() {
    const int n = 20;
    double dots_x[n], dots_y[n], maxim = 0, dist = 0;
    int num1, num2;
    for (int i = 0; i < n; i++) {
        cout << "x" << i << " & y" << i << ": " << endl;
        cin >> dots_x[i] >> dots_y[i];
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            if(i!=j)
            {
                dist = sqrt( (dots_x[i]-dots_x[j])*(dots_x[i]-dots_x[j]) + (dots_y[i]-dots_y[j])*(dots_y[i]-dots_y[j]) );
                cout<<"dist dot"<<i << " & dot" <<j<<" = "<<dist<<endl;
                if(dist>maxim)
                {
                    maxim = dist;
                    num1 = i;
                    num2 = j;
                }
            }
    }
    cout<<"maxim = "<<maxim << endl;
    cout<<"dot 1 = " << num1 << " & dot 2 = " << num2;
        return 0;
    }