#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
18. Построить список из n целых чисел.
Сформировать новый список из элементов исходного, стоящих на четных позициях.
*/
struct List
{
    int data;
    List* next;
};
void ListInit()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    List* begin = new List;
    List* pointer = begin;
    cout << "Enter List1: " << endl;
    cin >> pointer->data;
    pointer->next = 0;
    int count = 1;
    while (count < n)
    {
        pointer->next = new List;
        pointer = pointer->next;
        cout << "Enter List" << count++ << ": " << endl;
        cin >> pointer->data;
        pointer->next = 0;
    }

    List* newBegin = NULL;
    List* newPointer = NULL;
    pointer = begin;
    count = 0;
    int check = 0;
    while (pointer)
    {
        count++;
        if (count%2 == 0)
        {
            if (check == 0)
            {
                newBegin = new List;
                newPointer = newBegin;
                newPointer->data = pointer->data;
                newPointer->next = 0;
                check++;
            }
            else
            {
                newPointer->next = new List;
                newPointer = newPointer->next;
                newPointer->data = pointer->data;
                newPointer->next = 0;
            }
        }
        pointer = pointer->next;
    }
    newPointer = newBegin;
    count = 1;
    while (newPointer)
    {
        cout << "List" << count++ << ": " << newPointer->data << endl;
        newPointer = newPointer->next;
    }
}
int main()
{
    ListInit();
    return 0;
}