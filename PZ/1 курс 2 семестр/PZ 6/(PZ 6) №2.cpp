#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
2. Построить список из символов до появления первой точки. 
Заменить строчные латинские буквы прописными.
*/
struct List
{
    char data;
    List* next;
};
List* ListInit()
{
    List* begin = 0;
    char ch;
    cout << "Enter sentence:" << endl;
    cin >> ch;
    if (ch != '.')
    {
        if (isupper(ch)) ch = tolower(ch);
        begin = new List;
        begin->data = ch;
        begin->next = NULL;
        List* pointer = begin;
        cin >> ch;
        if (isupper(ch)) ch = tolower(ch);
        while (ch != '.')
        {
            pointer->next = new List;
            pointer = pointer->next;
            pointer->data = ch;
            cin >> ch;
            if (isupper(ch)) ch = tolower(ch);
            pointer->next = NULL;
        }
    }
    return begin;
}
void ListShow()
{
    List* begin = ListInit();
    List* pointer = begin;
    int count = 1;
    for (; pointer != 0; pointer = pointer->next)
        cout << "List" << count++ << ": " << pointer->data << endl;
}
int main()
{
    ListShow();
    return 0;
}