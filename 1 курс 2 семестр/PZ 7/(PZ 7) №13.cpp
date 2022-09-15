#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
13. Построить двунаправленный список символов. Вставить перед каждым символом цифры звездочку.
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
    List* pointer = begin;
    while (pointer)
    {
        if (isdigit(pointer->data))
        {
            if (pointer == begin)
            {
                List* temp = new List;
                temp->data = '*';
                temp->prev = 0;
                temp->next = begin;
                begin->prev = temp;
                begin = temp;
            }
            else
            {
                List* temp = new List;
                temp->data = '*';
                temp->next = pointer;
                temp->prev = pointer->prev;
                pointer->prev->next = temp;
            }
        }
        pointer = pointer->next;
    }
    pointer = begin;
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