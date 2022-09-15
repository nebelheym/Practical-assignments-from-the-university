#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
14. Создать список из n вещественных чисел. Удалить из списка наибольший и наименьший элементы.
*/
struct List
{
    double data;
    List* next;
};
List* Delete(List* begin, double min, double max) //удаление элемента списка
{
    //если список пуст
    if (begin == NULL)
    {
        return begin;
    }
    //если список не пуст
    List* temp = begin; //установка указателя temp на начало списка
    // удаление первого элемента списка
    if (temp->data == min|| temp->data == max)
    {
        begin = temp->next; //сдвиг указателя begin на второй элемент списка
        delete temp; //удаление первого элемента списка
        return begin;
    }
    // удаление внутри списка (и последнего элемента списка)
    List* t1 = temp->next; //установка указателя t1 на элемент, следующий за temp (на второй)
    while (t1)
    {
        if (temp->data == min || temp->data == max)
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
    pointer = begin;
    double max = begin->data, min = begin->data;
    while (pointer)
    {
        if (max < pointer->data)
            max = pointer->data;
        if (min > pointer->data)
            min = pointer->data;
        pointer = pointer->next;
    }
    cout << endl << "Max: " << max << endl;
    cout << "Min: " << min << endl << endl;
    int count = 1;
    pointer = begin;
    while (pointer)
    {
        if (pointer->data == min || pointer->data == max)
        {
            pointer = Delete(pointer, min, max);
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