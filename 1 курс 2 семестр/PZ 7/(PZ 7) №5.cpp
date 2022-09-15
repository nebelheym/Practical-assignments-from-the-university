#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
5. Дано натуральное число n. Создать список целых чисел
, , . b1  bn
Выяснить, верно ли, что для i=1,…,n
выполнено
. bi
 bni1

*/
struct List
{
    int data;
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
void CheckList(List* begin, int n)
{
    List* pointer = begin;
    List* end = 0;
    for(;pointer != 0; pointer = pointer->next) end = pointer;
    pointer = begin;
    bool flag = true;
    for (int i = 0; i < n; i++, pointer = pointer->next, end = end->prev)
        if (pointer->data != end->data){flag = false;break;}
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
void ShowList(List* begin)
{
    if (begin == 0){cout << "The list is empty\n";return;}
    List* pointer = begin;
    int count = 0;
    for (; pointer != 0; pointer = pointer->next, count++)
        cout << "List" << count << ": " << pointer->data << endl;
    cout << "\n";
}
int main()
{
    int n;
    List* begin = ListInit(n);
    CheckList(begin, n);
    ShowList(begin);
    return 0;
}