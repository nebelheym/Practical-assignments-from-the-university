#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
6. Дано натуральное число n. Построить список целых чисел...
*/
struct List
{
    int data;
    List* next;
};
List* ListInit()
{
    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    List* begin, * pointer;
    begin = new List;
    pointer = begin;
    pointer->next = 0;
    cout << "Enter List1:" << endl;
    cin >> pointer->data;
    for (int i = 1; i < n * 2; i++)
    {
        pointer->next = new List;
        pointer = pointer->next;
        pointer->next = 0;
        cout << "Enter List" << i + 1 << ":" << endl;
        cin >> pointer->data;
    }
    pointer = begin;
    List* end = NULL;
    for (int i = 0; i < n; i++)
    {
        pointer = pointer->next;
        end = pointer;
    }
    pointer = begin;
    bool flag = true;
    while (end)
    {
        if (pointer->data + end->data <= 10)
        {
            flag = false;
            break;
        }
        pointer = pointer->next;
        end = end->next;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return begin;
}
int main()
{
    List* begin = ListInit();
    return 0;
}