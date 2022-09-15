#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
11. Построить двунаправленный список из n целых чисел. Удалить из списка элемент с максимальным
значением.
*/
struct List
{
    int data;
    List* prev, * next;
};
List* ListInit()
{
    List* begin = NULL, * pointer = NULL, * temp;
    int n;
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
List* MaxDelete()
{
    List* begin = ListInit();
    List* pointer = begin;
    int max = pointer->data;
    pointer = pointer->next;
    while (pointer = pointer->next)
        if (max < pointer->data)
            max = pointer->data;
    pointer = begin;
    for (pointer; pointer != 0; pointer = pointer->next)
    {
        if (max == pointer->data)
        {
            if(pointer->prev != 0 && pointer->next != 0)
            {
                List* temp = pointer;
                List* tempPrev = pointer->prev;
                List* tempNext = pointer->next;
                delete temp;
                tempPrev->next = tempNext;
                tempNext->prev = tempPrev;
                break;
            }
            else if (pointer->prev == 0 && pointer->next != 0)
            {
                List* temp = pointer;
                pointer = pointer->next;
                pointer->prev = 0;
                delete temp;
                begin = pointer;
                break;
            }
            else
            {
                List* temp = pointer;
                pointer = pointer->prev;
                pointer->next = 0;
                delete temp;
                break;
            }
        }
    }
    return begin;
}
void ShowList()
{
    List* begin = MaxDelete();
    if (begin == 0) //если список пустой
    {
        cout << "The list is empty\n";
        return;
    }
    List* pointer = begin;
    int count = 0;
    while (pointer) //пока не конец списка
    {
        count++;
        cout << "List" << count << ": " << pointer->data << endl;
        pointer = pointer->next; //перейти на следующий
    }
    cout << "\n";
}
int main()
{
    ShowList();
    return 0;
}