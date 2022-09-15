#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    int x[3*n];
    for(int i = 0; i<3*n; i++)
    {
        cout << "Enter x" << "[" << i << "]:" << endl;
        cin >> x[i];
    }
    int xMax = x[0];
    for(int i = 0; i<n; i++)
    {
        if(xMax < x[i])
            xMax = x[i];
    }
    int y[2*n], j = 0;
    for(int i = 0; i<2*n; i++)
    {
        if(x[n+i] > xMax)
        {
            y[j] = x[n+i];
            j++;
        }
    }
    int sum = 0;
    for(int i = 0; i<j; i++)
        sum += y[i];
    cout << "Sum = " << sum;
    return 0;
}