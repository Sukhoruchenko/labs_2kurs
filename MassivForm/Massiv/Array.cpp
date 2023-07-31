#include "Array.h"

using namespace std;

Aarray::~Aarray()
{
	delete[] a;
}

Aarray Aarray::RandMas(int p)
{
	if (n != p) {
		delete[]a;
		n = p;
		a = new int[p];
	}

	for (int i = 0; i < p; i++)
		a[i] = rand() % 100;
	return *this;
}

Aarray Aarray::operator+(Aarray &B)
{
	int i = 0;
	n += B.n;
	Aarray Res(n);
	for (i = 0; i < n; i++)
		Res.a[i] = a[i];
	for (int j = 0; i < n; i++, j++)
		Res.a[i] = B.a[j];
	return Res;
}

Aarray Aarray::operator+=(Aarray &B)
{
	int *t;
	int i = 0;
	t = new int[n];
	for (i = 0; i < n; i++)
		t[i] = a[i];
	delete[]a;

	a = new int[n + B.n];
	for (int i = 0; i < n; i++)
		a[i] = t[i];
	n += B.n;
	for (int j = 0; i < n; i++, j++)
		a[i] = B.a[j];

	delete[]t;
	return *this;
}

void Aarray::Scan(int m)
{
	if (n != m)
	{
		delete[]a;
		n = m;
		a = new int[n];
	}
	cout << "enter" << ' ' << m << ' ' << "elements: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void Aarray::Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int Aarray::Find(int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key) return i;
	return -1;
}

Aarray::Aarray(int m)
{
	if (m == 0) m = 1;
	if (m < 0) m *= -1;
	n = m;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}

Aarray::Aarray(int *b, int m)
{
	n = m;
	a = new int[n];
	for (int i = 0; i < n; i++) a[i] = b[i];
}

Aarray::Aarray(Aarray &T)
{
	n = T.n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = T.a[i];
}

Aarray & Aarray::operator=(Aarray &B)
{
	if (this != &B)
	{
		if (n != B.n)
		{
			delete[] a;
			n = B.n;
			a = new int[n];
		}
		for (int i = 0; i < n; i++)
			a[i] = B.a[i];
	}
	return *this;
}

int & Aarray::operator[](int pos)
{
	if (pos<0 || pos>n)
	{
		cout << "incorrect pos, return a[0]";
		return a[0];
	}
	return a[pos];
}

Aarray & Aarray::operator+=(int key)
{
	int *t = new int[n + 1];
	for (int i = 0; i < n; i++)
		t[i] = a[i];
	t[n] = key;
	delete[] a;
	n++;
	a = t;
	return *this;
}

Aarray & Aarray::operator+(int key)
{
	Aarray Res(n + 1);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	Res.a[n] = key;
	return Res;

}

Aarray & Aarray::operator-=(int pos)
{
	ShiftLeft(pos);
	return *this;
}

Aarray & Aarray::operator-(int key)
{
	int pos = this->Find(key);
	if (pos != -1)
		this->ShiftLeft(pos);
	else cout << "key is absent" << endl;
	return *this;
}

bool Aarray::operator==(Aarray B)
{
	cout << "proverka na ravenstvo: ";
	if (n == B.n)
	{
		for (int i = 0; i < n; i++)
			if (a[i] != B.a[i]) cout << "false" << endl;
		return false;
		cout << "true" << endl;
		return true;
	}
	cout << "false" << endl;
	return false;
}

bool Aarray::operator!=(Aarray B)
{
	cout << "proverka na neravenstvo: ";
	if (n == B.n)
	{
		for (int i = 0; i < n; i++)
			if (a[i] != B.a[i]) cout << "true" << endl;
		return true;
		cout << "false" << endl;
		return false;
	}
	cout << "true" << endl;
	return true;

}

ostream & operator<<(ostream &r, Aarray &x)
{
	x.Print();
	return r;
}

istream & operator>>(istream &r, Aarray &x)
{
	int m;
	cout << "enter the number of element in array: ";
	cin >> m;
	if (x.n != m)
	{
		delete[] x.a;
		x.n = m;
		x.a = new int[m];
	}
	cout << "enter " << m << " elements: ";
	for (int i = 0; i < x.n; i++)
		r >> x.a[i];
	return r;
}

int Aarray::Min(int *a, int n)
{
	int  min = a[0], i;
	for (i = 0; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

int Aarray::Max(int *a, int n)
{
	int  max = a[0], i;
	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void Aarray::Sort()
{
	int c, i, m;
	for (c = n; c > 0; c--)
		for (i = 0; i < c - 1; i++)
			if (a[i] > a[i + 1]) {
				m = a[i];
				a[i] = a[i + 1];
				a[i + 1] = m;
			}
}

void Aarray::ShiftLeft(int pos)
{
	int i;
	if (pos < 0 || pos >= n)
	{
		cout << "incorrect pos" << endl;
		return;
	}
	int *t;
	t = new int[n];
	for (int i = 0; i < n; i++)
		t[i] = a[i];
	delete[]a;
	a = new int[n - 1];
	for (i = 0; i < pos; i++)
		a[i] = t[i];
	for (i = pos + 1; i < n; i++)
		a[i - 1] = t[i];
	delete[]t;
	n--;
}
