#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age:" << endl;
    cin >> age;
    if(age<0)
    {
        cout << "Eshe ne rodilsya";
    }
    else if(age<=3 && age>=0)
    {
        cout << "Rebenok";
    }
    if(age<7 && age>3)
    {
        cout << "Doshkolnik";
    }
    else if(age<18 && age>=7)
    {
        cout << "Uchen";
    }
    else if(age>=18 && age<60)
    {
        cout << "Pracivnik";
    }
    else if(age>=60 && age <= 122)
    {
        cout << "Pensioner";
    }
    else if(age>122)
    {
        cout << "Ludi stolko ne jivut";
    }
    return 0;
}