#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
12. Построить двунаправленный список из n целых чисел. 
Добавить в начало списка элемент, содержащий
сумму всех элементов списка, а в конец – элемент, 
содержащий произведение всех элементов списка.
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
    double sum = 0, product = 1;
    for (; pointer != 0; pointer = pointer->next)
    {
        sum += pointer->data;
        product *= pointer->data;
        end = pointer;
    }
    List* temp = new List;
    temp->data = sum;
    temp->prev = 0;
    temp->next = begin;
    begin->prev = temp;
    begin = temp;
    temp = new List;
    temp->data = product;
    temp->prev = end;
    temp->next = 0;
    end->next = temp;
    end = temp;
    pointer = begin;
    int count = 1;
    while (pointer)
    {
        cout << "List " << count++ << ": " << pointer->data << endl;
        pointer = pointer->next;
    }
}
int main()
{
    int n;
    List* begin = ListInit(n);
    SumList(begin, n);
    return 0;
}