#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");

    int n = 1;
    double dob = 1, ch = 2, zn = 1;

    for(;n <= 15;n++)
    {
        dob *= ch / zn;
        if (ch > zn) zn += 2;
        if (zn > ch) ch += 2;
    }
    cout << dob;

    return 0;
}
