#include <iostream>
using namespace std;

int main() {

    double angle, radian;
    const double p = 3.14;
    char operation;
    bool condition = true;

    do{
        cout << "Select the desired operation:" << endl;
        cout << "A: converting radians to angle" << endl;
        cout << "R: converting angle to radians" << endl;
        cout << "Q: to terminate the program" << endl;
        cin >> operation;

        switch(operation)
        {
            case 'A':
                cout << "Enter radians:" << endl;
                cin >> radian;
                angle = radian * 180/p;
                cout << radian << " radians equals " << angle << " degrees" << endl;
                        break;
            case 'R':
                cout << "Enter angle:" << endl;
                cin >> angle;
                radian = angle * p/180;
                cout << angle << " degrees equals " << radian << " radians" << endl;
            case 'Q':
                cout << "The program has ended";
                return 0;
        }
    }while(condition);

    return 0;
}