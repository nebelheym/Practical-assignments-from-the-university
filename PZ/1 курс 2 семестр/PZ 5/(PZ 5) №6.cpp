#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
6. Дан файл, содержащий сведения о телефонах абонентов: фамилия, год установки телефона, номер телефона.
Определить количество установленных телефонов с ХХХХ года и список абонентов.
*/
/*
Пример данных в файле:

Knyazev 2021 +380954333830
Tabolin 2015 +380967433120
Kushnirenko 2017 +380991311911
*/
struct Phone
{
    string surname;
    int year;
    string number;
};
string* edStr(string str, int& param)
{
    string nst, s;
    str += " ";
    int len = str.size(); //довжина введеного тексту
    int i = 0;
    string* arr = new string[param];
    int begin = 0, end = 0, count = 0;
    while (i < str.size() - 1)
    {
        while (isspace(str[i]) || ispunct(str[i]))
            ++i;      // пропустити пробіли 
        begin = i;                       // номер першого символу слова
        while (!isspace(str[i]) && !ispunct(str[i]))
            ++i;                       // пропустити символи слова
        end = i;     // номер символу, наступного за останнім символом слова
        s = str.substr(begin, end - begin);
        count++;
        switch (count)
        {
        case 1:
            arr[0] = s;
            break;

        case 2:
            arr[1] = s;
            break;

        case 3:
            arr[2] = s;
            break;
        }
    }
    return arr;
}
Phone* PhoneArrCreate(int& size, int& param)
{
    Phone* PhoneArr = new Phone[size];
    int PhoneCount = 0;
    string str;
    string* strArr = new string[param];
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    if (!fin.is_open())
    {
        cout << "File does not open!" << endl;
        return NULL;
    }
    while (!fin.eof())
    {
        getline(fin, str, '\n');
        strArr = edStr(str, param);
        PhoneArr[PhoneCount].surname = strArr[0];
        PhoneArr[PhoneCount].year = stoi(strArr[1]);
        PhoneArr[PhoneCount++].number = strArr[2];
    }
    fin.close();  //закрити файл
    return PhoneArr;
}
void PhoneCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 3;
    Phone* arr = PhoneArrCreate(size, param);
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    // Определить количество установленных телефонов с ХХХХ года
    int year;
    cout << "Enter year:" << endl;
    cin >> year;
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].year >= year)
            count++;
    cout << "Number of subscribers using the telephone since " << year << " is " << count << " people" << endl;
    fout << "Number of subscribers using the telephone since " << year << " is " << count << " people" << endl;
    // Cписок абонентов
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].surname << " " << arr[i].year << " " << arr[i].number << endl;
        fout << arr[i].surname << " " << arr[i].year << " " << arr[i].number << endl;
    }
    fout.close();
}
int main()
{
    PhoneCheck();
    return 0;
}