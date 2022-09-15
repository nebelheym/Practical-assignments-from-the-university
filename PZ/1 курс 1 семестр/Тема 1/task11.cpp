#include <iostream>
using namespace std;
int main()
{
    int x, y, result1, result2;
    double result3;
    cout << "Enter an integer x:" << endl;
    cin >> x;
    cout << "Enter an integer y:" << endl;
    cin >> y;
    result1 = x%y;
    result2 = x/y;
    result3 = static_cast<double>(x) / y; //Так как в задании было сказано ввести X и Y как целые числа, пришлось
    //преобразовывать их в числа с плавающей точкой для вычисления значений после запятой.
    cout << "Remainder when dividing: " << result1 << endl;
    cout << "Division of an integer by an integer: " << result2 << endl;
    cout << "Divide a floating point number by a floating point number: " << result3;
    return 0;
}