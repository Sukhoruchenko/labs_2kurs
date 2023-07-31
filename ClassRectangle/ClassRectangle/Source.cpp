#include "Header.h"

void main()
{
	Rect A,B;
	cout << "Rect1:" << endl;
	A.Input();
	cout << "Rect2:" << endl;
	B.Input();
	A.Center();
	//A.Mult(5);
	A.Square();
	A.Perimetr();
	A.Radious();
	A.Kvadrat();
	A.Ravenstvo(B);
	A.PodobieRects(B);
	A.PeresechenieRects(B);
	_getch();
}