#include <iostream>
using namespace std;
int main()
{
    int n, k, a, b, c, x, y, z;
    cout << "Enter integer n:" << endl;
    cin >> n;
    cout << "Enter integer k:" << endl;
    cin >> k;
    cout << "Enter integer a:" << endl;
    cin >> a;
    cout << "Enter integer b:" << endl;
    cin >> b;
    cout << "Enter integer c:" << endl;
    cin >> c;
    cout << "Enter integer x:" << endl;
    cin >> x;
    cout << "Enter integer y:" << endl;
    cin >> y;
    cout << "Enter integer z:" << endl;
    cin >> z;
//задание а (чётность)
    if (n%2 == 0)
    {
        if (k%2 == 0)
        {
            cout << "a)" << " true" << endl;
        }
        else
        {
            cout << "a)" << " false" << endl;
        }
    }
    else
    {
        if (k%2 != 0)
        {
            cout << "a)" << " true" << endl;
        }
        else
        {
            cout << "a)" << " false" << endl;
        }
    }
    //задание б (кратность)
    if (n%4 == 0)
    {
        if (n%5 != 0 && n%10 != 0)
        {
            cout << "b)" << " true" << endl;
        }
        else
        {
            cout << "b)" << " false" << endl;
        }
    }
    else
    {
        cout << "b)" << " false" << endl;
    }
    //задание в (среднее арифметическое)
    if (c == (a+b)/2)
    {
        cout << "v)" << " true" << endl;
    }
    else
    {
        cout << "v)" << " false" << endl;
    }
    //задание г (проверка на отрицательность чисел)
    if (x < 0)
    {
        if (y < 0)
        {
            if (z < 0)
            {
                cout << "g)" << " true" << endl;
            }
            else
            {
                cout << "g)" << " false" << endl;
            }
        }
        else
        {
            cout << "g)" << " false" << endl;
        }
    }
    else
    {
        cout << "g)" << " false" << endl;
    }
    //задание д (чётность только одного из чисел)
    int parity = 0;
    if (x%2 == 0)
    {
        parity += 1;
    }
    if (y%2 == 0)
    {
        parity += 1;
    }
    if (z%2 == 0)
    {
        parity += 1;
    }
    if (parity == 1)
    {
        cout << "d)" << " true" << endl;
    }
    else
    {
        cout << "d)" << " false" << endl;
    }
    //задание е (проверка больше ли числа чем 100)
    int morethan100 = 0;
    if (x > 100)
    {
        morethan100 += 1;
    }
    if (y > 100)
    {
        morethan100 += 1;
    }
    if (z > 100)
    {
        morethan100 += 1;
    }
    if (morethan100 >= 1)
    {
        cout << "e)" << " true" << endl;
    }
    else
    {
        cout << "e)" << " false" << endl;
    }
    //задание ж (принадлежность к отрезку)
    if (x >= 2 && x <= 5 || x >= -1 && x <= 1)
    {
        cout << "j)" << " true" << endl;
        cout << "z)" << " false" << endl;
    }
    else
    {
        cout << "j)" << " false" << endl;
        cout << "z)" << " true" << endl;
    }

    return 0;
}