#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
8. Дан файл f, содержащий сведения о пациентах глазной клиники: фамилия, пол, возраст, место проживания
(город), диагноз. Получить в файле g список пациентов старше Х лет с диагнозом Y.
/*
Пример данных в файле:

Knyazev Male 18 Dnipro Gastritis
Kushnireno Male 18 Kiverci Vision
Tabolin Male 18 Chernovci Back
*/
struct Patient
{
    string surname;
    string sex;
    int age;
    string city;
    string diagnosis;
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
            arr[count - 1] = s;
            break;

        case 2:
            arr[count - 1] = s;
            break;

        case 3:
            arr[count - 1] = s;
            break;
        case 4:
            arr[count - 1] = s;
            break;
        case 5:
            arr[count - 1] = s;
            break;
        }
    }
    return arr;
}
Patient* PatientArrCreate(int& size, int& param)
{
    Patient* PatientArr = new Patient[size];
    int PatientCount = 0;
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
        PatientArr[PatientCount].surname = strArr[0];
        PatientArr[PatientCount].sex = strArr[1];
        PatientArr[PatientCount].age = stoi(strArr[2]);
        PatientArr[PatientCount].city = strArr[3];
        PatientArr[PatientCount++].diagnosis = strArr[4];
    }
    fin.close();  //закрити файл
    return PatientArr;
}
void PatientCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 5;
    Patient* arr = PatientArrCreate(size, param);
    // Получить в файле g список пациентов старше Х лет с диагнозом Y.
    int X;
    string Y;
    cout << "Enter age: " << endl;
    cin >> X;
    cout << "Enter diagnosis: " << endl;
    cin >> Y;
    ofstream g;
    g.open("C:\\University\\LB PROG\\output.txt");
    for(int i = 0; i < size; i++)
        if (arr[i].age > X && arr[i].diagnosis == Y)
        {
            cout << arr[i].surname << " " << arr[i].sex << " " << arr[i].age << " " << arr[i].city << " " << arr[i].diagnosis << endl;
            g << arr[i].surname << " " << arr[i].sex << " " << arr[i].age << " " << arr[i].city << " " << arr[i].diagnosis << endl;
        }
    g.close();
}
int main()
{
    PatientCheck();
    return 0;
}