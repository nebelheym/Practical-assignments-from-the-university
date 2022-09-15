#include <iostream>
using namespace std;

int main() {

    int x, quad, cube, a100, a10, a1, sum;

    cout << "Enter x:" << endl;
    cin >> x;

    a100 = x/100;
    a10 = (x-a100*100)/10;
    a1 = x - a100*100 - a10*10;
    cout << a100 << " " << a10 << " " << a1 << endl;
    quad = pow(x, 2);
    sum = a100+a10+a1;
    cube = pow(sum, 3);

    //Проверка значений
    //cout << quad << endl;
    //cout << cube << endl;

    if(quad==cube)
    {
        cout << "The square of the entered three-digit number is equal to the cube of the sum of the digits of the entered three-digit number";
    }
    else
    {
        cout << "The square of the entered three-digit number is not equal to the cube of the sum of the digits of the entered three-digit number";
    }

    //Проблема задания в том, что равным значение может быть только при вводе числа 001
    //Во всех остальных случаях они не равны

    return 0;
}