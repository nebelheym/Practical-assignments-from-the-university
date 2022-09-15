#include <iostream>
#include <string>

using namespace std;

/*
1. В консольном приложении спроектировать класс Employee (служащие). 
Он должен хранить имена FirstName и фамилии LastName служащих. 
На основе класса Employee должны быть порождены классы 
HourlyWorker (работники с почасовой оплатой) и Boss (управляющие). HourlyWorker получают почасовую оплату. 
Boss получает фиксированную зарплату за неделю.
В класс Employee необходимо включить следующие функции:
1.  конструктор с аргументами Имя и Фамилия,  который копирует их в переменные FirstName и LastName;
2.  void Print() - вывод на экран имени и фамилии служащего;
Закрытыми переменными производного от Employee класса HourlyWorker  будут Wage (плата за час) и Hours (часы, отработанные за месяц). Класс необходимо дополнить функциями:
1.  переопределённой функцией Print() – она должна выводить на экран имя, фамилию и  заработную плату служащего;
2.  double GetPay() – подсчитывает и возвращает заработную плату работников с почасовой оплатой.
По аналогии с классом HourlyWorker создать класс Boss.
Написать программу, демонстрирующую работу с созданными классами.
*/

class Employee
{
public:
    string FirstName;
    string LastName;
    int salary;

    void constructor(string firstname, string lastname)
    {
        FirstName = firstname;
        LastName = lastname;
    }
    void Print()
    {
        cout << "FirstName: " << FirstName << " LastName: " << LastName << endl;
    }
};
class HourlyWorker : public Employee
{
public:
    double GetPay(int hours)
    {
        int hourly_payment = 200;
        salary = hours * hourly_payment;
        cout << FirstName << "'s salary is " << salary << endl;
        return salary;
    }
};
class Boss : public Employee
{
public:
    double GetPay(int weeks)
    {
        int fixed_payment = 10000;
        salary = weeks * fixed_payment;
        cout << FirstName << "'s salary is " << salary << endl;
        return salary;
    }
};
int main()
{
    HourlyWorker Danila;
    Danila.constructor("Danila", "Poperechniy");
    Danila.Print();
    Danila.GetPay(43);
    Boss Aziz;
    Aziz.constructor("Aziz", "Nurmagovedov");
    Aziz.Print();
    Aziz.GetPay(5);
}