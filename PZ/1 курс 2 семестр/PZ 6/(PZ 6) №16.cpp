#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
16. Ввести список символов, заканчивая ввод точкой. 
Слова в этом списке разделены пробелами. 
В каждом слове удалить первую букву.
*/
struct List
{
    char data;
    List* next;
};
List* Delete(List* begin, char key) //удаление элемента списка
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
    List* begin = 0;
    char ch;
    begin = new List;
    List* pointer = begin;
    pointer->data = ' ';
    pointer->next = NULL;
    cout << "Enter sentence:" << endl;
    ch = cin.get();
    while (ch != '.')
    {
        pointer->next = new List;
        pointer = pointer->next;
        pointer->data = ch;
        ch = cin.get();
        pointer->next = NULL;
    }
    return begin;
}
void ListShow()
{
    List* begin = ListInit();
    List* pointer = begin;
    while (pointer)
    {
        if (isspace(pointer->data) && pointer->data != '.')
        {
            if(pointer != begin && pointer->next->data)
                cout << " ";
            pointer = pointer->next;
            pointer = Delete(pointer, pointer->data);
            continue;
        }
        cout << pointer->data;
        pointer = pointer->next;
    }
}
int main()
{
    ListShow();
    return 0;
}