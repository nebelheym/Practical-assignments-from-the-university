#include <iostream>
using namespace std;
int main() {
    double A;
    cout << "Enter A:" << endl;
    cin >> A;
    double sum = 1, n = 1;
    bool condition = true;
    while(condition)
    {
        n++;
        sum += 1/n;
        if(sum > A)
            condition = false;
    }
    cout << "Sum = " << sum;
    return 0;
}