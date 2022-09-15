#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a = 1, variable, sum = 0;
    cout << "Enter n:" << endl;
    cin >> n;
    bool condition = true;
    while(condition)
    {
        a *= 10;
        variable = n/a;
        if(variable == 0)
            condition = false;
        sum += 1;
    }
    cout << "sum = " << sum << endl;
    return 0;
}