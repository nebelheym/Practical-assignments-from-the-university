#include <iostream>
using namespace std;
int main() {
    const int n = 50;
    char a[n], j = - 1;
    bool flag = true;
    cout << "Enter text:" << endl;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        j++;
        if(a[i] == '.')
            break;
    }
    for(int i = j; i>=0; i--)
        cout << a[i];
    cout << ' ' << endl;
    j--;
    for(int i = 0; i<j; i++)
    {
        if(a[i] != a[j])
        {
            flag = false;
            break;
        }
        j--;
    }
    if(flag)
        cout << "2 - Yes" << endl;
    else
        cout << "2 - No" << endl;
    return 0;
}