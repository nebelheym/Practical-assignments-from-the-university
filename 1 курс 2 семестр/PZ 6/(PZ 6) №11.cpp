#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
11. Создать список символов. Вставить после каждой цифры символ ‘*’.
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
void ListInsert()
{
    List* begin = ListInit();
    List* pointer = begin;
    while (pointer)
    {
        if (isdigit(pointer->data))
        {
            List* temp = new List;
            temp->data = '*';
            temp->next = pointer->next;
            pointer->next = temp;
        }
        pointer = pointer->next;
    }
    while (begin)
    {
        cout << begin->data;
        begin = begin->next;
    }
}
int main()
{
    ListInsert();
    return 0;
}