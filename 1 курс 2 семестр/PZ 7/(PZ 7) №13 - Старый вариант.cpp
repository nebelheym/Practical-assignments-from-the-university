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
List* ListInit()
{
    List* begin = NULL, * pointer = NULL, * temp;
    pointer = new List;
    begin = pointer;
    pointer->data = ' ';
    pointer->prev = NULL;
    pointer->next = NULL;
    cout << "Enter sentence: " << endl;
    char ch;
    ch = cin.get();
    if (ch != '.')
    {
        if (isdigit(ch))
        {
            temp = new List;
            temp->data = '*';
            pointer->next = temp;
            temp->prev = pointer;
            temp->next = NULL;
            pointer = temp;
        }
        temp = new List;
        temp->data = ch;
        pointer->next = temp;
        temp->prev = pointer;
        temp->next = NULL;
        pointer = temp;
        ch = cin.get();
        while (ch != '.')
        {
            if (isdigit(ch))
            {
                temp = new List;
                temp->data = '*';
                pointer->next = temp;
                temp->prev = pointer;
                temp->next = NULL;
                pointer = temp;
            }
            temp = new List;
            temp->data = ch;
            pointer->next = temp;
            temp->prev = pointer;
            temp->next = NULL;
            pointer = temp;
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
    List* begin = ListInit();
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