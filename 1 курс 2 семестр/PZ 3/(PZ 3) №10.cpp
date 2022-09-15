#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
10. Функции из библиотеки С, определенные в заголовочном файле <cmath>:
double abs(double);
double sin(double);
double cos(double);
double sqrt(double);
Объявите массив указателей на функции такого вида и инициализируйте его этими четырьмя
функциями. Вызовите эти функции по очереди через указатели.
 */
int main()
{
    double ((*math[4]))(double);
    math[0] =&abs;
    math[1] = sin;
    math[2] = cos;
    math[3] = sqrt;
    for(int i = 0; i < 4; i++)
        cout << math[i](10) << " ";
}