#include "Array.h"
using namespace std;

void main()
{
	Array mas1, mas2, mas4, mas5;
	int n, x, key, *b, max=0, min=0;
	mas1.Scan(5);//1)
	mas1.Print();//1)
	cout << "input key = ";//2)
	cin >> key;//2)
	mas1+=key;//2)
	cout <<"mas1: "<< mas1;//2)
	mas2 = mas1;//3)
	cout <<"mas2: "<< mas2;//3)
	mas2 -= 0;//4)
	cout << "mas2: " << mas2;//4)
	mas2 -= 4;//4)
	cout << "mas2: " << mas2;//4)
	mas1 - 1;//5)
	cout << "mas1: " << mas1;//5)
	mas1 == (mas2);//6)
	cout << "input n = ";//7)
	cin >> n;//7)
	b = new int[n];
	cout << "b: " ;//7)
	for (int i = 0; i < n; i++)//7)
	{
		b[i] = rand() % 10;
		cout << b[i] << ' ';
	}
	cout << endl;//7)	
	Array mas3(b, n);//7)
	cout << "mas3: " << mas3;//7)
	max=mas3.Max(b,n);//8)
	cout <<"max = " << max;//8)
	cout << endl;//8)
	min = mas3.Min(b, n);//8)
	cout << "min = " << min;//8)
	cout << endl;//8)
	mas3.Sort();//9)
	cout << "mas3: " << mas3;//9)
	mas1 == (mas3);//10)
	mas4 = mas1;//11)
	mas4 += mas3;//11)
	cout << "mas4: " << mas4;//11)
	mas2 += mas3;//12)
	cout << "mas2: " << mas2;//12)
	mas4 == (mas2);//13)
	mas4 != (mas2);//13)
	cin >> mas5;//14)
	cout << "mas5: " << mas5;//14)
	mas3 = mas5;//15)
	cout << "mas3: " << mas3;//15)
	_getch();
}