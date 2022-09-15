#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
17. Сформировать новый список из элементов списка целых чисел, 
имеющих значения больше среднего арифметического 
для положительных элементов исходного списка.
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
    pointer = begin;
    int average = 0;
    count = 0;
    while (pointer)
    {
        if (pointer->data > 0)
        {
            average += pointer->data;
            count++;
        }
        pointer = pointer->next;
    }
    average /= count;
    cout << "Average: " << average << endl;
    
    List* newBegin = NULL;
    List* newPointer = NULL;
    pointer = begin;
    int check = 0;
    while (pointer)
    {
        if (pointer->data > average)
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