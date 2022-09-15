#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
10. Создать двунаправленный список из n вещественных чисел. 
Удалить первый и последний элементы списка.
*/
struct List
{
    float data;
    List* prev, * next;
};
List* ListInit()
{
    int n, count = 1;
    cout << "Enter n: " << endl;
    cin >> n;

    List* begin = NULL, * pointer = NULL, * temp, *end;
    pointer = new List;
    begin = pointer;
    cout << "Enter a" << count << ": " << endl;
    float value;
    cin >> value;
    pointer->data = value;
    pointer->prev = NULL;
    pointer->next = NULL;
    while (count++ < n)
    {
        cout << "Enter a" << count << ": " << endl;
        cin >> value;
        temp = new List;
        temp->data = value;
        pointer->next = temp;
        temp->prev = pointer;
        temp->next = NULL;
        pointer = temp;
    }
    end = pointer;
    count = 0;
    pointer = begin->next;
    free(begin);
    temp = end;
    end = temp->prev;
    free(temp);
    n -= 2;
    begin = pointer;
    begin->prev = NULL;
    end->next = NULL;
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