#include <iostream>
using namespace std;
int main()
{
    int k, m, n;

    cin >> k >> m >> n;

    if (k%2 == 0 && m%2 == 0 && n%2 == 0)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}