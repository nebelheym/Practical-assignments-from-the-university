#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
1. Построить список из символов до появления первой точки. 
Поменять местами первый и последний символ списка.
*/
struct List
{
    char data;
    List* next;
};
List* ListInit()
{
    List* begin = 0;
    char ch;
    cout << "Enter sentence:" << endl;
    cin >> ch;
    if (ch != '.')
    {
        begin = new List;
        begin->data = ch;
        begin->next = NULL;
        List* pointer = begin;
        cin >> ch;
        while (ch != '.')
        {
            pointer->next = new List;
            pointer = pointer->next;
            pointer->data = ch;
            cin >> ch;
            pointer->next = NULL;
        }
    }
    return begin;
}
List* ListSwap()
{
    List* begin = ListInit();
    List* pointer = begin;
    List* end = 0;
    while (pointer != 0)
    {
        end = pointer;
        pointer = pointer->next;
    }
    pointer = begin;
    char temp = pointer->data;
    pointer->data = end->data;
    end->data = temp;
    return begin;
}
void ListShow()
{
    List* beginin = ListSwap();
    List* pointer = beginin;
    int count = 1;
    for (; pointer != 0; pointer = pointer->next)
        cout << "List" << count++ << ": " << pointer->data << endl;
}
int main()
{
    ListShow();
    return 0;
}