#include <iostream>
using namespace std;
int main()
{
    int a1, a2, a3, a4, n;

    cin >> a1 >> a2 >> a3 >> a4;

    if(a1 == a2 && a2 == a3)
    {
        n = 4;
        cout << n;
    }
    if(a2 == a3 && a3 == a4)
    {
        n = 1;
        cout << n;
    }
    if(a3 == a4 && a1 == a4)
    {
        n = 2;
        cout << n;
    }
    if(a1 == a2 && a2 == a4)
    {
        n = 3;
        cout << n;
    }

    return 0;
}