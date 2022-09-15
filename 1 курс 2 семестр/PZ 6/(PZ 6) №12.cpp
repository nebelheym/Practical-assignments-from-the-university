#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
12. Создать список из n вещественных чисел. Если список упорядочен по убыванию, 
продублировать его первые и последние элементы.
*/
struct List
{
    double data;
    List* next;
};
bool LessCheck(List* begin)
{
    List* pointer = begin;
    List* pointerNext = pointer->next;
    bool flag = true;
    while (pointerNext != 0)
    {
        if (pointer->data < pointerNext->data)
        {
            flag = false;
            break;
        }
        pointer = pointer->next;
        pointerNext = pointer->next;
    }
    return flag;
}
void ListInsert(List* pointer)
{
    List* temp = new List;
    temp->data = pointer->data;
    temp->next = pointer->next;
    pointer->next = temp;
}
List* ListInit()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    List* begin, * pointer;
    begin = new List;
    pointer = begin;
    List* end = begin;
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
    bool flag = LessCheck(begin);
    if (flag)
    {
        ListInsert(begin);
        ListInsert(end);
    }
    pointer = begin;
    int count = 1;
    while (pointer)
    {
        cout << "List" << count++ << ": " << pointer->data << endl;
        pointer = pointer->next;
    }
    return begin;
}
int main()
{
    ListInit();
    return 0;
}