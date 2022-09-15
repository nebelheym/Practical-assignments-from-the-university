#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter array size:" << endl;
    cin >> n;
    char s[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter s" << i << ": " << endl;
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '*')
        {
            for (i++; i < n; i++)
                s[i] = '-';
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "s" << i << " = " << s[i] << endl;
    }
    return 0;
}