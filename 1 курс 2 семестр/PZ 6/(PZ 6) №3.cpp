#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
3. Построить список из n целых чисел. 
Вычислить произведение первого, наибольшего и наименьшего чисел списка.
*/
struct List
{
    int data;
    List* next;
};
void ListInit()
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
    int first = pointer->data, max = pointer->data, min = pointer->data;
    pointer = pointer->next;
    for (int i = 1; i < n; i++)
    {
        pointer = new List;
        pointer = begin;
        pointer->next = 0;
        cout << "Enter List" << i + 1 << ":" << endl;
        cin >> pointer->data;
        if (max < pointer->data)
            max = pointer->data;
        if (min > pointer->data)
            min = pointer->data;
        pointer = pointer->next;
    }
    cout << "First: " << first << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Product: " << first * min * max;
}
int main()
{
    ListInit();
    return 0;
}