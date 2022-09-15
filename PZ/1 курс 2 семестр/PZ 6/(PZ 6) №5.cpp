#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
5. Создать список из n вещественных чисел. 
Сколько в списке чисел с минимальным значением среди положительных
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
    double min = NULL;
    pointer = begin;
    while (pointer)
    {
        if (pointer->data > 0)
        {
            min = pointer->data;
            break;
        }
        pointer = pointer->next;
    }
    if (min == NULL) cout << "No min" << endl;
    cout << "Min: " << min << endl;
    pointer = begin;
    while(pointer)
    {
        if (pointer->data > 0 && pointer->data < min)
            min = pointer->data;
        pointer = pointer->next;
    }
    int count = 0;
    pointer = begin;
    while (pointer)
    {
        if (pointer->data == min)
            count++;
        pointer = pointer->next;
    }
    cout << "Count of min: " << count;
    return begin;
}
int main()
{
    List* begin = ListInit();
    return 0;
}