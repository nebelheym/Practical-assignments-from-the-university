#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <math.h>
using namespace std;
float fact(int N)
{
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
float func(int n, int m)
{
    float c = fact(n) / (fact(m) * fact(n - m));
    return c;
}
int main()
{
    float c = func(8, 6);
    cout << "c: " << c;
    return 0;
}