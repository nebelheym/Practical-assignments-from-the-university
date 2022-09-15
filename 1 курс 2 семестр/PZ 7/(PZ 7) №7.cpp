#include <iostream>
#include <conio.h>
#include <string>
#include <fstream> //для роботы з файлами
#include <string>
#include <clocale>
#include <conio.h>  
using namespace std;
/*
7. Дано натуральное число n. Построить список вещественных чисел...
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
    while (count++ < n*2)
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
void ProductList(List* begin, int n)
{
    List* pointer = begin;
    List* end = 0;
    for (int i = 0; i < 2*n; i++)
    {
        end = pointer;
        pointer = pointer->next;
    }
    pointer = begin;
    double product = 1;
    while (pointer != end)
    {
        product *= (pointer->data + 2 * (end->data));
        pointer = pointer->next;
        end = end->prev;
    }
    cout << "Product: " << product;
}
int main()
{
    int n;
    List* begin = ListInit(n);
    ProductList(begin, n);
    return 0;
}