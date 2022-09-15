#include <iostream>
using namespace std;

int main() {

    int k, a100, a10, a1;

    cout << "Enter k:" << endl;
    cin >> k;

    a100 = k/100;
    a10 = (k - a100*100)/10;
    a1 = k - a100*100 - a10*10;

    if (a100 == 5 || a10 == 5 || a1 == 5)
    {
        cout << "Yes, the number 5 is included in the entered three-digit number";
    }
    else
    {
        cout << "No, the number 5 is not included in the entered three-digit number";
    }
    return 0;
}