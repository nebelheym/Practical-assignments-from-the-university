#include <iostream>
using namespace std;
int main()
{
    int variable;
    cout << "Enter a three-digit number:" << endl;
    cin >> variable;
    if (variable < 1000 && variable >= 100)
    {
        variable = variable / 100;
        cout << "The first digit of the number: " << variable;
    }
    else
    {
        cout << variable << " is not a 3-digit number";
    }
    return 0;
}