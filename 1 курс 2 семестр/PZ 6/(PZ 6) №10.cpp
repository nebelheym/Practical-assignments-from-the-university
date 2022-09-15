#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
10. Создать список из символов, вводимых с клавиатуры до появления символа «точка». 
Определить, сколько символов цифр входит в полученный список.
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
void ListCount()
{
    List* begin = ListInit();
    int count = 0;
    for (; begin != nullptr; begin = begin->next)
        if (isdigit(begin->data))
            count++;
    cout << "Count of digit's: " << count;
}
int main()
{
    ListCount();
    return 0;
}