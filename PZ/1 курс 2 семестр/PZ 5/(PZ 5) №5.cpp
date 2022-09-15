#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
5. Дан файл, содержащий сведения о сдаче студентами сессии: индекс группы, фамилия студента, оценки по пяти
экзаменам. Определить средний балл, полученный каждым студентом группы Х, и всей группой в целом.
*/
/*
Пример данных в файле:

21 Knyazev 100 90 95 97 94
22 Zinchenko 100 70 95 97 94
22 Kushnirenko 15 30 95 97 94
21 Shtirov 30 50 95 97 94
21 Tabolin 700 43 95 97 94
*/
struct Student
{
    int index;
    string surname;
    int Mark[5];
    int Average = 0;
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
        StudentArr[StudentCount].index = stoi(strArr[0]);
        StudentArr[StudentCount].surname = strArr[1];
        for (int i = 0; i < 5; i++)
        {
            StudentArr[StudentCount].Mark[i] = stoi(strArr[i + 2]);
            StudentArr[StudentCount].Average += StudentArr[StudentCount].Mark[i];
        }
        StudentArr[StudentCount].Average = StudentArr[StudentCount++].Average / 5;
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
    int param = 7;
    Student* arr = StudentArrCreate(size, param);
    // Переписать в новый файл удельные веса и названия всех полупроводников.
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    // Средний бал каждому студенту
    for (int i = 0; i < size; i++)
    {
        cout << "Average mark for " << arr[i].surname << " student " << arr[i].Average << endl;
        fout << "Average mark for " << arr[i].surname << " student " << arr[i].Average << endl;
    }
    // Средний бал по группе
    int** ArrGroup = new int* [size];
    for (int i = 0; i < size; i++)
        ArrGroup[i] = new int[3];
    bool flag;
    int GroupCount = 0;
    for (int i = 0; i < size; i++)
    {
        flag = false;
        for (int j = 0; j < GroupCount; j++)
        {
            if (arr[i].index == ArrGroup[j][0])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            ArrGroup[GroupCount++][0] = arr[i].index;
    }
    for (int i = 0; i < GroupCount; i++)
    {
        ArrGroup[i][1] = 0;
        ArrGroup[i][2] = 0;
        for (int j = 0; j < size; j++)
        {
            if (ArrGroup[i][0] == arr[i].index)
            {
                ArrGroup[i][1] += arr[i].Average;
                ArrGroup[i][2]++;
            }
        }
    }
    for (int i = 0; i < GroupCount; i++)
    {
        cout << "Group " << ArrGroup[i][0] << " have " << ArrGroup[i][1] / ArrGroup[i][2] << " average mark" << endl;
        fout << "Group " << ArrGroup[i][0] << " have " << ArrGroup[i][1] / ArrGroup[i][2] << " average mark" << endl;
    }
    fout.close();
}
int main()
{
    StudentCheck();
    return 0;
}