#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    if(n<=100 && n>=0)
    {
        if(n>=0 && n<10)
        {
            if(n==0 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9)
            {
                cout << n << " rokiv";
            }
            else if(n==1)
            {
                cout << n << " rik";
            }
            else
            {
                cout << n << " roki";
            }
        }
        else if(n >= 10 && n < 20)
        {
            cout << n << " rokiv";
        }
        else{
            k = n-n/10*10;
            if(k==0 || k == 5 || k == 6 || k == 7 || k == 8 || k == 9)
            {
                cout << n << " rokiv";
            }
            else if(k==1)
            {
                cout << n << " rik";
            }
            else
            {
                cout << n << " roki";
            }
        }
    } else
    {
        cout << "Error";
    }

    return 0;
}