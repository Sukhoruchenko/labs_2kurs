#include "Set.h"

using namespace std;

typedef unsigned char UC;
 
Set::Set() : BoolVector(256) { M = 0; }

Set::Set(char *s)
{
    n = 256; m = 32;
	bv = new UC[m];
	int i;
	for (i = 0; i<m; i++)
		bv[i] = 0;
	for (i = 0; s[i]; i++)
		SetUp1((UC)s[i]);
	M = Weight();
}

Set::Set(Set &S) : BoolVector(S) { M = S.M; }

Set & Set:: operator = (Set &S)
{
	if(this != &S)
	{
		for (int i = 0; i < 32; i++)
			bv[i] = S.bv[i];
		M = S.M;
	}
	return  *this;
}

Set Set:: operator+ (char ch) // V = *this + ch
{ 
	Set Res = *this;
	Res.SetUp1((UC)ch);
	Res.M = Res.Weight();
	return Res;
}

Set & Set:: operator += (char ch) //  *this = *this + ch
{ 
	SetUp1((UC)ch);
	 M = Weight();
	 return *this;
}

Set Set::operator+(Set S)
{
	Set Res = *this;
	for (int i = 0; i < 32; i++)
		Res.bv[i] |= S.bv[i];
	Res.M = Res.Weight();
	return Res;
}

Set & Set::operator+=(Set S)
{
	for (int i = 0; i < 32; i++)
		bv[i] |= S.bv[i];
	M = Weight();
	return *this;
}

Set Set::operator-(char ch)
{
	Set Res = *this;
	Res.SetUp0((UC)ch);
	Res.M = Res.Weight();
	return Res;
}

Set & Set::operator-=(char ch)
{
	SetUp0((UC)ch);
	M = Weight();
	return *this;

}

Set Set:: operator-(Set S)// Res = *this - S
{ 
	Set Res = *this, V = S;
	~V;
	 Res &= V;
	 Res.M = Res.Weight();
	 return Res;
}

Set & Set::operator-=(Set S)
{
	S = ~S;
	*this &= S;
	M = Weight();
	return *this;
}

Set Set::operator*(Set S)
{
	Set Res = *this;
	Res &= S;
	Res.M = Res.Weight();
	return Res;
}

Set Set::operator*=(Set S)
{
	*this &= S;
	M = Weight();
	return *this;
}

Set Set:: operator~() // дополнение к универсальному
{
	for (int i = 0; i < 32; i++)
		bv[i] = ~bv[i];
	M = Weight();
	return *this; 
}

bool Set::operator==(Set S)
{
	if (S.M == M)
	{
		for (int i = 0; i < 32; i++)
			if (bv[i] != S.bv[i])
				return false;
		return true;
	}
	else 
		return false;
}


bool Set::operator!=(Set S)
{
	if (S.M == M)
	{
		for (int i = 0; i < 32; i++)
			if (bv[i] != S.bv[i])
				return true;
		return false;
	}
	else
		return true;
}


char  Set::Max()
{
	for (int i = 256 - 1; i >= 0; i--)
		if (operator[](i) == '1')
			return char (i);
}

void Set::Scan(int n)
{
	cout << "input elements set, M =  " << n << ": ";
	char *s;
	s = new char[n + 1];
	gets_s(s, n + 1);
	for (int i = 0; s[i]; i++)
		SetUp1((UC)s[i]);
	M = Weight();
	delete[] s;

}

void Set::Print()
{
	cout << "{ ";
	for (int i = 0; i < 256; i++)
		if (operator[](i) == '1')
			cout << char(i) << ' ';
	cout << "}";
	cout << " kol - vo elements = " << M << endl;
}

ostream & operator << (ostream & r, Set & S)
{
	S.Print();
	return r;
}

istream & operator>>(istream & r, Set & S)
{
	cout << "enter kol - vo elements = ";
	int n;
	cin >> n;
	S.Scan(n);
	S.M = S.Weight();
	return r;
}
