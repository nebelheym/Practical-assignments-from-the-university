#include <iostream>
#include <cmath>

using namespace std;

int fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}

int main()
{
    double x, y, result;

        cout << "Enter x:" << endl;
        cin >> x;
        cout << "Enter y:" << endl;
        cin >> y;

        result = (1 + x / fact(2) + y / fact(3)) / (1 + 2 / (3 + x * y));

        cout << "Result is:" << endl;
        cout << result;
    return 0;
}