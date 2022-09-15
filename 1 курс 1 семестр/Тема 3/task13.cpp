#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double product = 1;
    for(double i = 1; i<=52; i++)
    {
        product *= (i*i)/(i*i+2*i+3);
    }
    cout << "Product is: " << product;
    return 0;
}