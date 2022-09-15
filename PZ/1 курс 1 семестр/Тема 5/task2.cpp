#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    int a[n], result, chislitel = 0, znaminatel = 0;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter a" << i+1 << ":" << endl;
        cin >> a[i];
        if(a[i]%2 != 0)
            a[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0)
        cout << "a" << i+1 << " = " << a[i] << endl;
    }
    return 0;
}