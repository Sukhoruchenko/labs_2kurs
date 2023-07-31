#include "Array.h"

using namespace std;
 
void main()
{
	Array <char> mas1(5), mas2, mas3, mas4;
	int m = 0;
	char max, min, key;
	mas1.Scan(5);
	mas1.Print();
	cout << "enter key ";
	cin >> key;
	cout << "key= " << key;
	cout << endl;
	mas1 += key;
	cout << "mas1: " << mas1;
	cin >> mas2;
	cout << "first mas2: " << mas2;
	mas2 = mas1;
	cout << "second mas2: " << mas2;
    int n = 5;
	char *a = new char[n];
	cout << "input 5 elements a: ";
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
		cout << a[i] << ' ';
	}
	cout << endl;
	Array <char> b(a, n);
	cout << "b: ";
	b.Print();
	char pos = b[3];
	cout << "in this pos[3] = " << pos << endl;
	int k = b.Find('d');
	cout << "number element in mas = " << k << endl;
	mas3.Scan(5);
	mas3.Print();
	mas4 = mas3;
	mas4.Print();
	mas1 == (mas2);
	if (mas1 != (mas2)) cout << "mas1 != (mas2)";
	else cout << " mas1 = (mas2) ";
	cout << endl;
	max = mas3.Max(a, n);
	cout << "max = " << max;
	cout << endl;
	min = mas3.Min(a, n);
	cout << "min = " << min;
	cout << endl;
	mas3.Sort();
	cout << "mas3: " << mas3;
	if (mas1 == (mas3)) cout << "mas1 == (mas3)";
	else cout << " mas1 != (mas3) ";
	_getch();
}

