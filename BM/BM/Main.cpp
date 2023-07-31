#include "BoolMatrix.h"
#include <iostream>
#include <locale.h>
#include<conio.h>

using namespace std;

int main()
{
	BoolMatrix B1(4, 20);
	cout << "Matrix B1 4x20: " << endl;
	cout << B1;
	B1.Invert(8, 0, 10);
	B1.SetUp1(6, 1, 14);
	B1.SetUp1(6, 2, 8);
	for (int i = 1; i < 20; i += 2)
		B1.SetUp1(1, 3, i);
	cout << "New Matrix B1 4x20:" << endl;
	cout << B1;
	BoolMatrix B2;
	B2 = B1;
	cout << "Matrix B2 4x20:" << endl;
	cout << B2;
	B2.ShiftRightEq(0, 6);
	B2.ShiftLeftEq(2, 6);
	B2.SetUp0(1,16);
	B2.SetUp0(1,18);
	for (int i = 0; i < 20; i += 2)
		B2.Invert(1, 3, i);
	cout << "New Matrix B2 4x20:" << endl;
	cout << B2;
	char ** s = new char*[4];
	for (int i = 0; i < 4; i++)
		s[i] = new char[4];
     s[0] = "11111111111111111111";
	 s[1] = "1010101010";
	 s[2] = "1111111111";
	 s[3] = "111100001111";
	 BoolMatrix B3(s, 4);
	 cout << "Matrix B3:" << endl << B3;
	 BoolMatrix C1, C2, C3, C4;
	 cout << " Matrix C1:" << endl << C1;
	 if (C1 == B1) cout << " C1 = B1" << endl;
	 else cout << "C1 != B1" << endl;
	 C1 = B1 & B2;
	 C2 = B1 | B2;
	 C3 = B1 ^ B2;
	 C4 = ~B3;
	 cout << "Matrix C1:" << endl << C1;
	 cout << "Matrix C2:" << endl << C2;
	 cout << "Matrix C3:" << endl << C3;
	 cout << "Matrix C4:" << endl << C4;
	 B1 &= B2;
	 cout << "B1 &= B2:" << endl << B1;
	 if (C1 == B1) cout << " C1 = B1";
	 else cout << "C1 != B1" << endl;
	 cout << "B1[1]: " << B1[1] << endl;
     cout << "B1[1][19] = " << B1[1][19] << endl;
	cout << "B1[1][18] = " << B1[1][18] << endl;
	BoolVector res(B1.Disj());
	 cout << "B1.Disj(): " << endl << res;
	 BoolVector res1(B1.Xor());
	 cout << "B1.Xor(): " << endl << res1;
	_getch();
}