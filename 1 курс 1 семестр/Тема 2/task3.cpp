#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double x, y, z, result, result1, result2, result3;
    cin >> x >> y >> z;

    result1 = sqrt(x+y+z);
    result2 = 1.5 * x * y * z;
    result3 = 0.1 * ((x*y)/z);

    if(result1<result2 && result1<result3)
    {
        result = result1;
    }
    else if(result2<result3 && result2<result1)
    {
        result = result2;
    }
    else
    {
        result = result3;
    }

    cout << result;

    return 0;
}
