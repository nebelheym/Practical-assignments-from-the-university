#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
13. Построить список из n целых чисел. Удалить из списка отрицательные числа.
*/
struct List
{
    int data;
    List* next;
};
List* Delete(List* begin) //удаление элемента списка
{
    //если список пуст
    if (begin == NULL)
    {
        return begin;
    }
    //если список не пуст
    List* temp = begin; //установка указателя temp на начало списка
    // удаление первого элемента списка
    if (temp->data < 0)
    {
        begin = temp->next; //сдвиг указателя begin на второй элемент списка
        delete temp; //удаление первого элемента списка
        return begin;
    }
    // удаление внутри списка (и последнего элемента списка)
    List* t1 = temp->next; //установка указателя t1 на элемент, следующий за temp (на второй)
    while (t1)
    {
        if (t1->data < 0)
        {
            temp->next = t1->next; //связывание предыдущего со следующим за удаляемым
            delete t1; //удаление элемента списка
            return begin;
        }
        temp = t1; //переход на следующий элемент
        t1 = t1->next; //переход на следующий элемент
    }
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
    int count = 1;
    pointer = begin;
    while (pointer)
    {
        if (pointer->data < 0)
        {
            pointer = Delete(pointer);
            continue;
        }
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