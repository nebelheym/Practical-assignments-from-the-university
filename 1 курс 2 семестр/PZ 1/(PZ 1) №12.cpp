#include <iostream>
#include<string.h>
#include <conio.h>
using namespace std;
/*
12. Даны символьные массивы С1(n) и С2(m). 
Определить общее число строчных гласных латинских букв
(a,e,i,o,u) в этих массивах.
*/
// Самая красивая задачка которуя я когда-либо писал в своей жизни :3
char* ArrCreate(int size)
{
    char* arr = new char[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    return arr;
}
void CharCount(int& count, char* arr)
{
    const char* ConditionArr = "aeiou";
    for (int i = 0; arr[i]; i++)
        for (int j = 0; ConditionArr[j]; j++)
            if (arr[i] == ConditionArr[j])
                count++;
}
int main()
{
    unsigned int n, m;
    cout << "Enter n:" << endl;
    cin >> n;
    cout << "Enter m:" << endl;
    cin >> m;
    int count = 0;
    char* C1 = ArrCreate(n);
    char* C2 = ArrCreate(m);
    CharCount(count, C1);
    CharCount(count, C2);
    cout << "Count:\t" << count << endl;
    return 0;
}