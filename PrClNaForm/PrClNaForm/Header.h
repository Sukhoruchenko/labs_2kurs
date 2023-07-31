#pragma once
#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

using namespace std;


class Rect
{

private:
	float x, y, a, b;
public:
	Rect();
	Rect(float x, float y, float a, float b);
	Rect Center();
	Rect Mult(int);
	float Square();
	float Perimetr();
	float Radious();
	void Input();
	void Output();
	bool Kvadrat();
	bool Ravenstvo(Rect);
	bool PodobieRects(Rect);
	bool PeresechenieRects(Rect);
};

Rect::Rect()
{
	x = 0, y = 0, a = 0, b = 0;
}

Rect::Rect(float X, float Y, float A, float B)
{
	x = X; y = Y; a = A; b = B;
}

float Rect::Square()
{
	float S;
	S = a * b;
	cout << "S:" << S;
	cout << endl;
	return S;
}

float Rect::Perimetr()
{
	float P;
	P = a + b;
	cout << "P:" << P;
	cout << endl;
	return (a + b) * 2;
}

float Rect::Radious()
{
	float R;
	R = (sqrt(a * a + b * b)) / 2;
	cout << "R:" << R;
	cout << endl;
	return R;
}

Rect Rect::Center()
{
	float x1, y1;
	x1 = (x + (a / 2));
	y1 = (y - (b / 2));
	cout << "Center:" << x1 << ';' << y1;
	cout << endl;
	return *this;
}

Rect Rect::Mult(int n)
{
	a = a * n;
	b = b * n;
	cout << "Mult:";
	(*this).Output();
	cout << endl;
	return *this;
}

void Rect::Input()
{
	cout << "input point x :";
	cin >> x;
	cout << endl << "input point y :";
	cin >> y;
	cout << endl;
	cout << "input a:";
	cin >> a;
	cout << endl << "input b:";
	cin >> b;
	cout << endl;
}

void Rect::Output()
{
	cout << "point:" << x << ';' << y << endl << " a: " << a << ' ' << "b:" << b << endl;
}

bool Rect::Kvadrat()
{
	if (a = b) return true;
	else return false;
}

bool Rect::Ravenstvo(Rect ABCD)
{
	cout << "proverka na ravenstvo:";
	if (((a == ABCD.a) && (b == ABCD.b)) || ((a == ABCD.b) && (b = ABCD.b)))
	{
		cout << "true" << endl;
		return true;
	}
	else
		cout << "false" << endl;
	return false;
}

bool Rect::PodobieRects(Rect ABCD)
{
	cout << "proverka na podobie:";
	if ((a / ABCD.a == b / ABCD.b) || (a / ABCD.b == b / ABCD.b))
	{
		cout << "true" << endl;
		return true;
	}
	else
		cout << "false" << endl;
	return false;
}

bool Rect::PeresechenieRects(Rect Z)
{
	cout << "proverka na peresechenie:";
	if (((x <= (Z.x + Z.a)) && ((Z.x + Z.a) <= (x + a)) && (y >= (Z.y - Z.b)) && ((Z.y - Z.b) >= (y - b))) ||   //x,y-координаты точки Прям1
		(((x <= (Z.x + Z.a)) && (Z.x + Z.a) <= x + a) && (y >= Z.y) && (Z.y >= (y - b))) ||   //Z.x,Z.y-координаты точки Прям2
		((x <= Z.x) && ((Z.x <= (x + a)) && (y >= (Z.y - Z.b)) && ((Z.y - Z.b) >= (y - b)))) ||   //a,b-длины сторон Прям1
		((x <= Z.x) && ((Z.x <= (x + a)) && (y >= Z.y) && (Z.y >= (y - b)))))              //Z.a,Z.b-длины сторон Прям2
	{
		cout << "true" << endl;
		return true;
	}
	else
		cout << "false" << endl;
	return false;
}

