#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
3. Построить двунаправленный список символов до появления первой точки. 
Поменять местами первый и последний символ списка.
*/
struct List
{
    char data;
    List* prev, * next;
};
List* ListInit(List*& end)
{
    List* begin = NULL, * pointer = NULL, * temp;

    cout << "Enter sentence: " << endl;
    char ch;
    ch = cin.get();
    if (ch != '.')
    {
        pointer = new List;
        begin = pointer;
        pointer->data = ch;
        pointer->prev = NULL;
        pointer->next = NULL;
        ch = cin.get();
        while (ch != '.')
        {
            temp = new List;
            temp->data = ch;
            pointer->next = temp;
            temp->prev = pointer;
            temp->next = NULL;
            pointer = temp;
            end = pointer;
            ch = cin.get();
        }
    }
    temp = new List;
    temp->data = '.';
    pointer->next = temp;
    temp->prev = pointer;
    temp->next = NULL;
    pointer = temp;
    return begin;
}
void ShowList()
{
    List* end;
    List* begin = ListInit(end);
    char temp = begin->data;
    begin->data = end->data;
    end->data = temp;
    List* pointer = begin;
    while (pointer)
    {
        cout << pointer->data;
        pointer = pointer->next;
    }
}
int main()
{
    ShowList();
    return 0;
}