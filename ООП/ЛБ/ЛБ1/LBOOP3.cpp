#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
3.  Напишите иерархию наследования для классов 
Quadrilateral (четырехугольник), Trapezoid (трапеция) и Rectangle (прямоугольник). 
Используйте Quadrilateral как базовый класс иерархии. Защищёнными данными класса 
Quadrilateral должны быть пары координат (x, y) четырех угловых точек четырехугольника. 
Открытые функции класса Quadrilateral:
1.	конструктор по умолчанию, в котором всем координатам присваивается значение 0;
2.	функция SetCoord() для установки значений 4-х пар координат;
3.	функция Print() для вывода значений всех координат на экран.
Класс Trapezoid следует дополнить функцией 
Area(), возвращающей площадь трапеции. 
Функция Print() должна выводить на экран координаты и площадь трапеции.
В классе Trapezoid тоже должен быть конструктор по умолчанию.
Класс Rectangle подобен классу Trapezoid.
Написать программу, демонстрирующую работу с созданными классами.

*/

class Quadrilateral
{
protected:
	struct Dot
	{
		int x, y;
	};
	Dot FirstDot;
	Dot SecondDot;
	Dot ThirdDot;
	Dot FourthDot;
public:
	Dot DotArr[4] = {FirstDot, SecondDot, ThirdDot, FourthDot};
	Quadrilateral()
	{
		for (int i = 0; i < 4; i++)
		{
			DotArr[i].x = 0;
			DotArr[i].y = 0;
		}
	}
	void SetCord()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Enter x & y for " << i + 1 << " dot:" << endl;
			cin >> DotArr[i].x;
			cin >> DotArr[i].y;
		}
	}
	void Print()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Dot " << i + 1 << " coordinates: [" << DotArr[i].x << ";" << DotArr[i].y << "]" << endl;
		}
	}
};
class Trapezoid : public Quadrilateral
{
public:
	double SideArr[4];
	double h;
	void SideCalc()
	{
		SetCord();
		for (int i = 0; i < 4; i++)
		{
			if (i == 3)
			{
				SideArr[i] = sqrt((DotArr[3].x - DotArr[0].x)* (DotArr[3].x - DotArr[0].x) + 
					(DotArr[3].y - DotArr[0].y)* (DotArr[3].y - DotArr[0].y));
			}
			else SideArr[i] = sqrt((DotArr[i + 1].x - DotArr[i].x) * (DotArr[i + 1].x + 
				DotArr[i].x) + (DotArr[i + 1].y - DotArr[i].y) * (DotArr[i + 1].y - DotArr[i].y));
		}
		double a = SideArr[3];
		double b = SideArr[1];
		double c = SideArr[0];
		double d = SideArr[2];
		cout << "a: " << a << " b:" << b << " c:" << c << " d:" << d << endl;
		h = sqrt(c * c - ((((((a - b) * (a - b) + c * c - d * d)) * ((a - b) * (a - b) + c * c - d * d))) / (2 * (a - b))));
	}
	double Square;
	void Area()
	{
		double a = SideArr[3];
		double b = SideArr[1];
		Square = 0.5 * (a+b) * h;
	}
	void Print()
	{
		cout << "Area: " << Square << endl;
		cout << "h: " << h << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "Side" << i + 1 << ": " << SideArr[i] << endl;
			cout << "Dot " << i + 1 << " coordinates: [" << DotArr[i].x << ";" << DotArr[i].y << "]" << endl;
		}
	}
};
class Rectangle : public Trapezoid
{
public:
	int a, b;
	void SideCalc()
	{
		cout << "Zashlo v Rec" << endl;
		SetCord();
		for (int i = 0; i < 2; i++)
		{
			SideArr[i] = sqrt((DotArr[i + 1].x - DotArr[i].x) * (DotArr[i + 1].x +
				DotArr[i].x) + (DotArr[i + 1].y - DotArr[i].y) * (DotArr[i + 1].y - DotArr[i].y));
		}
		a = SideArr[0];
		b = SideArr[1];
	}
	void Area()
	{
		Square = a*b;
	}
	void Print()
	{
		cout << "a: " << a << " b: " << b << endl;
		cout << "Area: " << Square << endl;
		for(int i = 0; i < 4; i++)
			cout << "Dot " << i + 1 << " coordinates: [" << DotArr[i].x << ";" << DotArr[i].y << "]" << endl;
	}
};
int main()
{
	cout << "Quadrilateral: " << endl;
	Quadrilateral First;
	First.SetCord();
	First.Print();
	cout << "Trapezoid: " << endl;
	Trapezoid Second;
	Second.SideCalc();
	Second.Area();
	Second.Print();
	cout << "Rectangle: " << endl;
	Rectangle Third;
	Third.SideCalc();
	Third.Area();
	Third.Print();
}