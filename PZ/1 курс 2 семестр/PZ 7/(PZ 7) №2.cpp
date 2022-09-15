#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
2. Создать двунаправленный список из n вещественных чисел. 
Определить число вхождений в список его наибольшего элемента.
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
    double max = begin->data;
    for (; pointer != 0; pointer = pointer->next)
        if (max < pointer->data)
            max = pointer->data;
    pointer = begin;
    int count = 0;
    while (pointer)
    {
        if (pointer->data == max)
           count++;
        pointer = pointer->next;
    }
    cout << "Max: " << max << endl;
    cout << "Count of max: " << count;
}
int main()
{
    int n;
    List* begin = ListInit(n);
    SumList(begin, n);
    return 0;
}