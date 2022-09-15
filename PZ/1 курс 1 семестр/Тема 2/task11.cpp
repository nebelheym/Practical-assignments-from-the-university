#include <iostream>
using namespace std;

int main() {

    int x, a1, a2, a3, a4;
    cout << "Enter x:" << endl;
    cin >> x;
    a1 = x/1000;
    a2 = (x-a1*1000)/100;
    a3 = (x-a1*1000-a2*100)/10;
    a4 = x-a1*1000-a2*100-a3*10;
   //cout << a1 << " " << a2 << " " << a3 << " " << a4;
    if(a1 == a4 && a2 == a3)
    {
        cout << "This number is a palindrome";
    } else
    {
        cout << "This number is not a palindrome";
    }
    return 0;
}