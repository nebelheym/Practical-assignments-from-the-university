#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
4. Дан файл f, содержащий сведения о веществах: название вещества, его удельный вес и
проводимость (проводник, полупроводник, изолятор). Переписать в новый файл удельные веса и
названия всех полупроводников.
*/
/*
Пример данных в файле:

Aurum 500 Conductor
Argentum 300 Semiconductor
Bronze 100 Insulator
*/
struct Substances
{
    string name;
    int gravity;
    string conductivity;
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
Substances* SubstancesArrCreate(int& size, int& param)
{
    Substances* SubstancesArr = new Substances[size];
    int SubstancesCount = 0;
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
        SubstancesArr[SubstancesCount].name = strArr[0];
        SubstancesArr[SubstancesCount].gravity = stoi(strArr[1]);
        SubstancesArr[SubstancesCount++].conductivity = strArr[2];
    }
    fin.close();  //закрити файл
    return SubstancesArr;
}
void SubstancesCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 3;
    Substances* arr = SubstancesArrCreate(size, param);
    // Переписать в новый файл удельные веса и названия всех полупроводников.
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].gravity << " " << arr[i].conductivity << endl;
        fout << arr[i].gravity << " " << arr[i].conductivity << endl;
    }
    fout.close();
}
int main()
{
    SubstancesCheck();
    return 0;
}