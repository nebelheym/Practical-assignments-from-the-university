#include <iostream>
using namespace std;

int main() {
    int mark;
    cout << "Enter mark:" << endl;
    cin >> mark;
    if(mark==2)
    {
        cout << "Nezadovilno";
    }
    else if(mark==3)
    {
        cout << "Zadovilno";
    }
    else if(mark==4)
    {
        cout << "Dobre";
    }
    else if(mark==5)
    {
        cout << "Vidminno";
    }
    else
    {
        cout << "Error";
    }
    return 0;
}