#include "Set.h"
#include <iostream>
#include <locale.h>
#include <conio.h>

using namespace std;

int main()
{
	Set S1, S2, S3, S4, S5;
	cout << "S1: " << endl;
	S1.Scan(5);
    S1.Print();
	char v = 0;
	v = S1.Max();
	cout << "v= " << v << endl;
	S1 -= '1';
	S1.Print();
	cout << "S2: " << endl;
	S2.Scan(4);
	S2.Print();
	if (S1 == S2) cout << "S1 = S2";
	else cout << "S1 != S2";
	cout << endl;
	S1 += '1';
	S1 += S2;
	cout << "S1: " << S1 << endl;
	cout << "S3: " << endl;
	S3.Scan(5);
	S3.Print();
	S2 -= S3;
	cout << "S2: " << S2 << endl;
	if (S3 != S1) cout << "S3 != S1";
	else cout << "S3 = S1";
	cout << endl;
	cout << "S4: " << endl;
	S4.Scan(5);
	S4.Print();
	S3 *= S4;
	cout << "S3: " << S3 << endl;
	cout << "S5: " << endl;
	S5.Scan(5);
	S5.Print();
	S5 += '5';
	cout << "S5: " << S5 << endl;
    _getch();
}