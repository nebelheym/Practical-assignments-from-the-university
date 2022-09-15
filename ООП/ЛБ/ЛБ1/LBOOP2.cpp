#include <iostream>
#include <string>

using namespace std;

/*
2. Создайте иерархию классов Point – Circle – Cylinder. 
Класс Point (точка) должен содержать  координаты точки - х и у. 
Их следует объявить с квалификатором protected (защи¬щенные).
Откры¬тая часть класса Point должна содержать следующие  функции:
1.	конструктор по умолчанию, в котором x и y присваивается значение 0;
2.	функцию SetPoint(int x, int y) для изменения x и y, новые координаты должны быть переданы в функцию в качестве аргументов;
3.	функцию Print() для вывода координат на экран в форме [ x, y ].
Класс Circle (круг), производный от класса Point, должен хранить радиус круга, также его следует дополнить 
функциями SetRadius(int r) (установка радиуса) и Area(), которая возвращает площадь круга. 
Переопределённая функция Print() должна выводить на экран координаты центра круга и его радиус. 
В классе Circle тоже должен быть конструктор по умолчанию.
Класс Cylinder (цилиндр), производный от Circle, должен содержать 
переменную Height – высоту цилиндра, 
дополнительные функции SetHeight(int h) и Volume() (вычисляет объём цилиндра), 
Print() должна выводить [x, y] и объём цилиндра на экран.
Написать программу, демонстрирующую работу с созданными классами.
*/

class Point
{
protected:
	int x, y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	void SetPoint(int X, int Y)
	{
		x = X;
		y = Y;
	}
	void Print()
	{
		cout << "[ " << x << ", " << y << " ]" << endl;
	}
};
class Circle : public Point
{
public:
	int Radius;
	double Square;

	void SetRadius(int r)
	{
		Radius = r;
	}
	void Area()
	{
		Square = Radius * Radius;
	}
	void Print()
	{
		cout << "[ " << x << ", " << y << " ]" << " Radius = " << Radius << " (Square test: " << Square << ")" << endl;
	}
};
class Cylinder : public Circle
{
public:
	int Height;
	double Volume;

	void SetHeight(int h)
	{
		Height = h;
	}
	void SetVolume()
	{
		Volume = 3.14 * Radius * Radius * Height;
	}
	void Print()
	{
		cout << "[ " << x << ", " << y << " ]" << " Volume = " << Volume << endl;
	}
};
int main()
{
	Point First;
	First.SetPoint(5, 10);
	First.Print();

	Circle Second;
	Second.SetPoint(-10, 11);
	Second.SetRadius(5);
	Second.Area();
	Second.Print();

	Cylinder Third;
	Third.SetPoint(3, 5);
	Third.SetRadius(11);
	Third.SetHeight(7);
	Third.SetVolume();
	Third.Print();
}