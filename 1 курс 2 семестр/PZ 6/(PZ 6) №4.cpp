#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
4. Создать список из n вещественных чисел. 
Заменить отрицательные элементы значением последнего элемента списка.
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
    List* begin, * pointer, *end = 0;
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
        end = pointer;
    }
    cout << end->data << endl;
    pointer = begin;
    while (pointer)
    {
        if (pointer->data < 0)
            pointer->data = end->data;
        pointer = pointer->next;
    }
    return begin;
}
void ListShow()
{
    List* begin = ListInit();
    List* pointer = begin;
    int count = 1;
    while (pointer)
    {
        cout << "List" << count++ << ": " << pointer->data << endl;
        pointer = pointer->next;
    }
}
int main()
{
    List* begin = ListShow();
    return 0;
}