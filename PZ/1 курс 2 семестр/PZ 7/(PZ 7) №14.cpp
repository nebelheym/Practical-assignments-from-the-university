#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
14. Создать двунаправленный список из n вещественных чисел. 
Переписать в однонаправленный список все отрицательные элементы исходного списка.
*/
struct List
{
    double data;
    List* prev, * next;
};
struct SmallList
{
    double data;
    SmallList* next;
};
List* ListInit(int& n)
{
    List* begin = NULL, * pointer = NULL, * temp;
    cout << "Enter n: " << endl;
    cin >> n;
    int count = 1;
    begin = new List;
    pointer = begin;
    pointer->prev = NULL;
    pointer->next = NULL;
    cout << "List " << count << ":\t" << endl;
    cin >> pointer->data;
    while (count++ < n)
    {
        temp = pointer->next;
        temp = new List;
        temp->prev = pointer;
        pointer->next = temp;
        pointer = temp;
        pointer->next = 0;
        cout << "List " << count << ":\t" << endl;
        cin >> pointer->data;
    }
    return begin;
}
void CheckList(List* begin, int n)
{
    List* pointer = begin;
    SmallList* newBegin = nullptr;
    SmallList* newPointer = nullptr;
    bool check = false;
    while (pointer)
    {
        if (pointer->data < 0)
        {
            if (!check)
            {
                newBegin = new SmallList;
                newPointer = newBegin;
                newPointer->data = pointer->data;
                newPointer->next = nullptr;
                check = true;
            }
            else
            {
                newPointer->next = new SmallList;
                newPointer = newBegin->next;
                newPointer->data = pointer->data;
                newPointer->next = 0;
            }
        }
        pointer = pointer->next;
    }
    newPointer = newBegin;
    int count = 1;
    while (newPointer)
    {
        cout << "SmallList " << count++ << ": " << newPointer->data << endl;
        newPointer = newPointer->next;
    }
}
int main()
{
    int n;
    List* begin = ListInit(n);
    CheckList(begin, n);
    return 0;
}