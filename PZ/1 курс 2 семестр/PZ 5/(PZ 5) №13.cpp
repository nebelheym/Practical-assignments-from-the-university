#include <iostream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
#include <fstream>
using namespace std;
/*
13. Дан файл, содержащий информацию о багаже пассажиров (номер квитанции, количество вещей,
общий вес багажа).
а) Найти число пассажиров, имеющих более двух вещей и число пассажиров, количество вещей
которых превосходит среднее количество вещей.
б) Выяснить, имеется ли пассажир, багаж которого превышает багаж каждого из остальных пассажиров
и по числу вещей, и по весу.
/*
/*
Пример данных в файле:

N25554 5 100
N19234 1 14
N12421 4 16
N12313 24 204
N34234 14 64
*/
struct Baggage
{
    string number;
    int items;
    int weight;
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
Baggage* BaggageArrCreate(int& size, int& param)
{
    Baggage* BaggageArr = new Baggage[size];
    int BaggageCount = 0;
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
        BaggageArr[BaggageCount].number = strArr[0];
        BaggageArr[BaggageCount].items = stoi(strArr[1]);
        BaggageArr[BaggageCount++].weight = stoi(strArr[2]);
    }
    fin.close();  //закрити файл
    return BaggageArr;
}
void BaggageCheck()
{
    ifstream fin;
    fin.open("C:\\University\\LB PROG\\input.txt");
    int size = 0;
    string str;
    while (getline(fin, str))
        ++size;
    fin.close();
    int param = 3;
    Baggage* arr = BaggageArrCreate(size, param);
    ofstream fout;
    fout.open("C:\\University\\LB PROG\\output.txt");
    // а) Найти число пассажиров, имеющих более двух вещей и число пассажиров, количество вещей которых превосходит среднее количество вещей.
    int average = 0;
    for (int i = 0; i < size; i++)
        average += arr[i].items;
    average /= size;
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].items > 2)
            count++;
    cout << "Number of passengers whose number of items is above 2: " << count << endl;
    count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i].items > average)
            count++;
    cout << "Number of passengers whose number of items is above average: " << count << endl;
    // б) Выяснить, имеется ли пассажир, багаж которого превышает багаж каждого из остальных пассажиров и по числу вещей, и по весу.
    int maxItems = arr[0].items;
    int maxWeight = arr[0].weight;
    for (int i = 0; i < size; i++)
    {
        if (maxItems < arr[i].items)
            maxItems = arr[i].items;
        if (maxWeight < arr[i].weight)
            maxWeight = arr[i].weight;
    }
    for (int i = 0; i < size; i++)
        if (arr[i].items == maxItems && arr[i].weight == maxWeight)
            cout << "Number: " <<  arr[i].number << " Items: " << arr[i].items << " Weight: " << arr[i].weight << endl;
    fout.close();
}
int main()
{
    BaggageCheck();
    return 0;
}