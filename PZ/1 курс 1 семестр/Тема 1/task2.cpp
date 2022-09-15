#include <iostream>
using namespace std;
int main()
{
    char task;
    double x, y, z, a, b, e, p;
    bool var = true;

    do {
        cout << "Choose operation:" << endl;
        cout << "Enter A for example A" << endl;
        cout << "Enter B for example B" << endl;
        cout << "Enter Q for exit" << endl;
        cin >> task;

        switch (task) {
            case 'A':

                cout << "Task 2(a)" << endl;
                e = 2.72;
                cout << "Enter x:" << endl;
                cin >> x;
                cout << "Enter y:" << endl;
                cin >> y;
                cout << "Enter z:" << endl;
                cin >> z;
                a = a = ((sqrt(abs(x - 1))) - pow(abs(y), 1.0/3)) / 1 + (pow(x,2)) / 2 + pow(y,2) / 4;
                b = x * (atan(z) + pow(e, (-1 * (x + 3))));
                cout << "a = " << a << endl;
                cout << "b = " << b << endl;
                break;

            case 'B':

                cout << "Task 2(b)" << endl;
                p = 3.14;
                cout << "Enter x:" << endl;
                cin >> x;
                cout << "Enter y:" << endl;
                cin >> y;
                cout << "Enter z:" << endl;
                cin >> z;
                a = (2*cos(x - p/6))/(1.0/2 + sin(y*y));
                b = 1 + (tan(z / 2) * tan(z / 2));
                cout << "a = " << a << endl;
                cout << "b = " << b << endl;
                break;

            case 'Q':
                var = false;

            default:
                cout << "Enter A, B or Q." << endl;
        }
    }while (var);
    return 0;
}