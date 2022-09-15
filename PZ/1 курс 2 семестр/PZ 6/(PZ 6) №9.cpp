#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
9. Создать список из n вещественных чисел. 
Поменять местами наибольший и наименьший элементы списка.
*/
struct List
{
    double data;
    List* next;
};
List* ListInit()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    List* begin, * pointer;
    begin = new List;
    pointer = begin;
    pointer->next = 0;
    cout << "Enter List1:" << endl;
    cin >> pointer->data;
    for (int i = 1; i < n; i++)
    {
        pointer->next = new List;
        pointer = pointer->next;
        pointer->next = 0;
        cout << "Enter List" << i + 1 << ":" << endl;
        cin >> pointer->data;
    }
    pointer = begin;
    double max = begin->data, min = begin->data;
    List* maxP = begin, * minP = begin;
    while (pointer)
    {
        if (max < pointer->data)
        {
            max = pointer->data;
            maxP = pointer;
        }
        if (min > pointer->data)
        {
            min = pointer->data;
            minP = pointer;
        }
        pointer = pointer->next;
    }
    minP->data = max;
    maxP->data = min;
    return begin;
}
void ShowList()
{
    List* begin = ListInit();
    int count = 1;
    for (; begin != nullptr; begin = begin->next)
        cout << "List" << count++ << ": " << begin->data << endl;
}
int main()
{
    ShowList();
    return 0;
}