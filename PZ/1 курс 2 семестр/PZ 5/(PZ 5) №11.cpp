#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
11. Задан файл, содержащий фамилию, имя, отчество, группу и оценки студентов за последнюю сессию.
а) Вывести фамилии и инициалы студентов, сдавших сессию без троек.
б) Переписать в новый файл фамилии и названия групп тех студентов, которые имеют хотя бы одну
/*
/*
Пример данных в файле:

Knyazev Sergey Vitalievich KN21d 100 90 95 97 94
Zinchenko Irina Danilovna KN21d 100 70 95 97 94
Kushnirenko Timofey Otchestvo KN21d 15 30 95 97 94
Shtirov Andrey Otchestvo KN21d 30 50 95 97 94
Tabolin Alexandr Otchestvo KN21d 70 43 95 97 94
*/
struct Student
{
    string surname;
    string name;
    string patronymic;
    string group;
    int Mark[5];
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
        case 4:
            arr[3] = s;
            break;
        case 5:
            arr[4] = s;
            break;
        case 6:
            arr[5] = s;
            break;
        case 7:
            arr[6] = s;
            break;
        case 8:
            arr[7] = s;
            break;
        case 9:
            arr[8] = s;
            break;
        }
    }
    return arr;
}
Student* StudentArrCreate(int& size, int& param)
{
    Student* StudentArr = new Student[size];
    int StudentCount = 0;
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
        StudentArr[StudentCount].surname = strArr[0];
        StudentArr[StudentCount].name = strArr[1];
        StudentArr[StudentCount].patronymic = strArr[2];
        StudentArr[StudentCount].group = strArr[3];
        for (int i = 0; i < 5; i++)
            StudentArr[StudentCount].Mark[i] = stoi(strArr[i + 4]);
        StudentCount++;
    }
    fin.close();  //закрити файл
    return StudentArr;
}
void StudentCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 9;
    Student* arr = StudentArrCreate(size, param);
    // а) Вывести фамилии и инициалы студентов, сдавших сессию без троек.
    // б) Переписать в новый файл фамилии и названия групп тех студентов, которые имеют хотя бы одну
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    bool flag;
    for (int i = 0; i < size; i++)
    {
        flag = true;
        for (int j = 0; j < 5; j++)
        {
            if (arr[i].Mark[j] <= 60)
            {
                flag = false;
                break;
            }
        }
        if (flag) // Выводим на экран тех, у кого нет ни одной тройки
        {
            cout << arr[i].surname << " " << arr[i].name[0] << "." << arr[i].patronymic[0] << ". " << arr[i].group << " ";
            for (int j = 0; j < 5; j++)
                cout << arr[i].Mark[j] << " ";
            cout << endl;
        }
        else // Переписываем в файл (и на экран для проверки) тех, у кого есть хотя бы одна тройка
        {
            cout << arr[i].surname << " " << arr[i].name[0] << "." << arr[i].patronymic[0] << ". " << arr[i].group << " ";
            for (int j = 0; j < 5; j++)
                cout << arr[i].Mark[j] << " ";
            cout << endl;
            fout << arr[i].surname << " " << arr[i].name[0] << "." << arr[i].patronymic[0] << ". " << arr[i].group << " ";
            for (int j = 0; j < 5; j++)
                fout << arr[i].Mark[j] << " ";
            fout << endl;
        }
    }    
    fout.close();
}
int main()
{
    StudentCheck();
    return 0;
}