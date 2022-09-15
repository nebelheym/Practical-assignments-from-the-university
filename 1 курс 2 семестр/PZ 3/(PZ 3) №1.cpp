#include <iostream>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;
/*
1. Вывести на экран в порядке возрастания все четные числа из диапазона, границы которого вводятся
с клавиатуры. Границы могут вводиться в произвольном порядке. Вывод должен осуществляться
рекурсивной функцией.
 */
void ShowDiapazone(int left, int right)
{
    if(left%2 != 0)
        left++;
    cout << left << " ";
    if (left != right)  ShowDiapazone(left+2, right);
}
int main()
{
    ShowDiapazone(5, 10);
}