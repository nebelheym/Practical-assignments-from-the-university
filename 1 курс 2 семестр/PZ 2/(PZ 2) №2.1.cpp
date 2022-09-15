#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
Задание 2.1. Создайте функцию print:
*/
void print(double value, const char* name2, const char* name1, const char* name3)
{
    cout << "\n" << name1 << "\t" << name2 << "\t" << name3 << "\t" << value;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    print(10, "Иванов", "Студент:", "Средний бал");
    print(8, "Иванов", "Студент:", "Средний бал");
    print(6, "Сидоров", "Студент:", "Средний бал");
    print(11, "Колесник", "Аспирант", "Средний бал");
    print(2000, "слов в", "колличество", "статье");
    return 0;
}