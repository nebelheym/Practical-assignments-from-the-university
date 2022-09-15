#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
4. Ввести N и список действительных чисел A1,A2...A n. 
Получить max(A1+An ,A 2+ A-n-1 ..., An + A1).
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
void MaxList(List* begin, int n)
{
    List* pointer = begin;
    List* end = 0;
    for (; pointer != 0; pointer = pointer->next) end = pointer;
    pointer = begin;
    double max = begin->data + end->data;
    while (pointer)
    {
        if (max < pointer->data + end->data)
            max = pointer->data + end->data;
        pointer = pointer->next;
        end = end->prev;
    }
    cout << "Max: " << max << endl;
}
int main()
{
    int n;
    List* begin = ListInit(n);
    MaxList(begin, n);
    return 0;
}