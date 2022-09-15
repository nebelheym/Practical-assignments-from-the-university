#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
9. Написать функцию multiple, которая определяет для пары целых чисел, кратно ли второе число
первому. Функция должна воспринимать два целых аргумента и возвращать 1 (истина), если второе число
кратно первому, и 0 (ложь), если нет. Напишите объявление указателя на нее. Вызовите функцию через этот
указатель.
 */
bool multiple(int val1, int val2)
{
    if(val1%val2 == 0) return 1;
    else return 0;
}
int main()
{
    bool(*check)(int, int) = &multiple;
    cout << check(10,5);
}