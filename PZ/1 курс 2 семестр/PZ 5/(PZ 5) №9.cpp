#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
9. Дан файл f, содержащий сведения об экспортируемых товарах: указывается наименование товара,
страна, импортирующая товар, и объем поставляемой партии в штуках. Найти страны, в которые
экспортируется данный товар, и общий объем его экспорта.
/*
Пример данных в файле:

Oil Ukraine 600
Iron USA 200
Oil Japan 1000
Wood USA 300
Gold USA 500
*/
struct Export
{
    string name;
    string country;
    int volume;
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
        }
    }
    return arr;
}
Export* ExportArrCreate(int& size, int& param)
{
    Export* ExportArr = new Export[size];
    int ExportCount = 0;
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
        ExportArr[ExportCount].name = strArr[0];
        ExportArr[ExportCount].country = strArr[1];
        ExportArr[ExportCount++].volume = stoi(strArr[2]);
    }
    fin.close();  //закрити файл
    return ExportArr;
}
void ExportCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    int param = 3;
    fin.close();
    Export* arr = ExportArrCreate(size, param);
    // Найти страны, в которые экспортируется данный товар, и общий объем его экспорта.
    for (int i = 0; i < size; i++) // Для удобства выводим информацию из файла в консоль
        cout << arr[i].name << " " << arr[i].country << " " << arr[i].volume << endl;
    string name;
    cout << "Enter product name:" << endl;
    cin >> name;
    int sum = 0;
    string* Country = new string[param];
    int CountryCount = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].name == name)
            sum += arr[i].volume;
    cout << "Total export is " << sum << endl;
    bool flag;
    for (int i = 0; i < size; i++)
    {
        flag = false;
        if (arr[i].name == name)
        {
            for (int j = 0; j < CountryCount; j++)
            {
                if (arr[i].country == Country[j])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag) Country[CountryCount++] = arr[i].country;
        }
    }
    cout << "Countries to which this product is exported: ";
    for (int i = 0; i < CountryCount; i++)
        cout << Country[i] << " ";
}
int main()
{
    ExportCheck();
    return 0;
}