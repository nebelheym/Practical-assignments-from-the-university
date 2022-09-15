#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
8. Дано натуральное число n. Создать список вещественных чисел...
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
    for (int i = 0; i < n; i++)
    {
        end = pointer;
        pointer = pointer->next;
    }
    pointer = begin;
    double sum = 0;
    while (pointer)
    {
        sum += (sqrt(abs(pointer->data)) - end->data) * (sqrt(abs(pointer->data)) - end->data);
        pointer = pointer->next;
        end = end->prev;
    }
    cout << "Sum: " << sum;
}
int main()
{
    int n;
    List* begin = ListInit(n);
    SumList(begin, n);
    return 0;
}