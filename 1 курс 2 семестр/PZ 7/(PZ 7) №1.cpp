#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
1. Ввести двунаправленный список из n вещественных чисел. 
Заменить все нулевые элементы списка суммой первого и последнего элементов.
*/
struct List
{
    double data;
    List* prev, * next;
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
void SumList(List* begin, int n)
{
    List* pointer = begin;
    List* end = 0;
    for (; pointer != 0; pointer = pointer->next) end = pointer;
    pointer = begin;
    double sum = begin->data + end->data;
    while (pointer)
    {
        if (pointer->data == 0)
            pointer->data = sum;
        pointer = pointer->next;
    }
}
void ShowList(List* begin)
{
    if (begin == 0) { cout << "The list is empty\n"; return; }
    List* pointer = begin;
    int count = 0;
    for (; pointer != 0; pointer = pointer->next, count++)
        cout << "List" << count << ": " << pointer->data << endl;
    cout << "\n";
}
int main()
{
    int n;
    List* begin = ListInit(n);
    SumList(begin, n);
    ShowList(begin);
    return 0;
}