#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a[20], n[20], result, chislitel = 0, znaminatel = 0;
    for(int i = 0; i < 20; i++)
    {
        cout << "Enter a" << i+1 << ":" << endl;
        cin >> a[i];
        cout << "Enter n" << i+1 << ":" << endl;
        cin >> n[i];
        chislitel += a[i]*n[i];
        znaminatel += n[i];
    }
    result = chislitel/znaminatel;
    cout << "Result = " << result;
    return 0;
}