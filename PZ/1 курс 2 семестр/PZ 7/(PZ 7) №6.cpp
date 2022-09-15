#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
6. Дано натуральное число n. Создать список из n целых чисел. Выяснить, верно ли, что для...
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
void BoolList(List* begin, int n)
{
    List* pointer = begin;
    List* end = 0;
    for (; pointer != 0; pointer = pointer->next) end = pointer;
    pointer = begin;
    bool flag = true;
    while (pointer != end)
    {
        if (pointer->data < end->data)
        {
            flag = false;
            break;
        }
        pointer = pointer->next;
        end = end->prev;
    }
    if (flag) cout << "Yes";
    else cout << "No";
}
int main()
{
    int n;
    List* begin = ListInit(n);
    BoolList(begin, n);
    return 0;
}