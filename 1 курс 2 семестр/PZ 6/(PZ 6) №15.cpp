#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
15. Создать список из n вещественных чисел. Если список упорядочен по возрастанию, 
удалить первые k элементов списка.
*/
struct List
{
    double data;
    List* next;
};
bool GreaterCheck(List* begin)
{
    List* pointer = begin;
    List* pointerNext = pointer->next;
    bool flag = true;
    while (pointerNext != 0)
    {
        if (pointer->data > pointerNext->data)
        {
            flag = false;
            break;
        }
        pointer = pointer->next;
        pointerNext = pointer->next;
    }
    return flag;
}
List* Delete(List* begin, double key) //удаление элемента списка
{
    //если список пуст
    if (begin == NULL)
    {
        return begin;
    }
    //если список не пуст
    List* temp = begin; //установка указателя temp на начало списка
    // удаление первого элемента списка
    if (temp->data == key)
    {
        begin = temp->next; //сдвиг указателя begin на второй элемент списка
        delete temp; //удаление первого элемента списка
        return begin;
    }
    // удаление внутри списка (и последнего элемента списка)
    List* t1 = temp->next; //установка указателя t1 на элемент, следующий за temp (на второй)
    while (t1)
    {
        if (temp->data == key)
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
    int check = 0;
    int k = 0;
    pointer = begin;
    bool flag = GreaterCheck(begin);
    if (flag)
    {
        cout << "Enter k: " << endl;
        cin >> k;
    }
    while (pointer)
    {
        if (check < k)
        {
            pointer = Delete(pointer, pointer->data);
            check++;
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