#include <iostream>
#include <string>
#include <math.h>

using namespace std;

/*
4. Создайте иерархию классов Point – Square – Cube. 
Класс Point (точка) должен содержать  координаты точки - x и у. 
Их следует объявить с квалификатором protected (защи¬щенные).

Откры¬тая часть класса Point должна содержать следующие  функции:
1.	конструктор по умолчанию, где координатам следует присвоить значение 0;
2.	функцию SetPoint(int x, int y) для изменения x и y, 
новые координаты должны быть переданы в 
функцию в качестве аргументов;
3.	функцию Print() для вывода координат на экран в форме [ x, y ].
Класс Square (квадрат), производный от класса Point, 
должен хранить сторону квадрата, также его следует дополнить 
функцией SetSide(int side) для изменения стороны квадрата и функцией 
Area(), которая возвращает площадь квадрата. Переопределённая функция 
Print() должна выводить на экран координаты центра квадрата и его сторону.
В классе Square должен быть конструктор по умолчанию.

В класс Cube (куб), производный от Square, нужно включить функцию 
Volume() для  вычисления объёма куба, конструктор без аргументов, 
Print() должна выводить [x, y] и объём куба на экран.
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
class Square : public Point
{
public:
	int Side;
	int SquareArea;

	void SetSide(int arg_side)
	{
		Side = arg_side;
	}
	void SquareCalc()
	{
		SquareArea = Side*Side;
	}
	void Print()
	{
		cout << "[ " << x << ", " << y << " ]" << " Side: " << Side << " Area: " << SquareArea << endl;
	}
};
class Cube : public Square
{
public:
	double Volume;

	void VolumeCalc()
	{
		Volume = Side*Side*Side;
	}
	void Print()
	{
		cout << "[ " << x << ", " << y << " ]" << " Volume: " << Volume << endl;
	}
};
int main()
{
	cout << "Point: " << endl;
	Point First;
	First.SetPoint(4, 5);
	First.Print();
	cout << "Square: " << endl;
	Square Second;
	Second.SetPoint(4, 6);
	Second.SetSide(5);
	Second.SquareCalc();
	Second.Print();
	cout << "Cube: " << endl;
	Cube Third;
	Third.SetPoint(11, 3);
	Third.SetSide(7);
	Third.VolumeCalc();
	Third.Print();
}