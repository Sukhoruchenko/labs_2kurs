#include "Header.h"

using namespace std;

int BoolVector::Input(char *s, int i_s, int i_bv, int N)
{
	//формированием эл-та bv[i_bv]
	//i_s -индекс символа в s
    //N -кол-во значащих цифр в bv[i_bv]
	{UC mask = 1;
	int j = 0;
	mask <<= (N - 1);
	bv[i_bv] = 0;
	for (int i = i_s; j < N; j++, i++, i_s++, mask >>= 1)
		if (s[i] == '1') bv[i_bv] |= mask;
	return i_s;
	}
}

BoolVector::BoolVector()
{
	n = 0;
	m = 1;
	bv = new UC[m];
	bv[0] = 0;
}

BoolVector::BoolVector(int N)
{
	n = N;
	m = N / 8;
	int k = N % 8;
	if (k) m++;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = 0;
}

BoolVector::BoolVector(char* s)
{
	n = strlen(s);
	m = n / 8;
	int k = n % 8;
	if (k) m++;
	bv = new UC[m];
	int i_bv = 0, i_s = 0;
	if (k) 
	{
		i_s = Input(s, i_s, i_bv, k);
		i_bv++;
	}
	for (; i_bv < m; i_bv++)
		i_s = Input(s, i_s, i_bv, 8);
}

BoolVector::BoolVector(char * s, int N)
{
	int lenght_s = strlen(s);
	if (N == lenght_s) BoolVector(s);
	else
		if (N < lenght_s) 
		{
			n = N;
			//m = (n + 7) / 8; -Надо знать сколько значащих позиций ,поэтому ->
			m = n / 8;
			int k = N % 8;
			if (k)
				m++;
			bv = new UC[m];

			int i_bv = 0, i_s = lenght_s-N  ;
			if (k)
			{
				i_s = Input(s, i_s, i_bv, k);
				i_bv++;
			}
			for (; i_bv < m; i_bv++)
				i_s = Input(s, i_s, i_bv, 8);
		}
		else 
		{
			int i;
			n = N;
			m = n / 8;
			int k = N % 8;
			if (k) m++;
			bv = new UC[m];
			int m1 = lenght_s / 8;
			int k1 = lenght_s % 8;
			if (k1) m1++;
			if (m - m1 >= 0)
				for (i = 0; i < m - m1; i++)
					bv[i] = 0;
			int i_bv = i, i_s = 0;
			if (k1)
			{
				i_s = Input(s, i_s, i_bv, 8 - k1);
				i_bv++;
			}
			for (; i_bv < m; i_bv++)
				i_s = Input(s, i_s, i_bv, 8);
		}
}

BoolVector::BoolVector(BoolVector &V)
{
	n = V.n;
	m = V.m;
	bv = new UC[m];
	for (int i = 0; i < m; i++)
		bv[i] = V.bv[i];
}

BoolVector::~BoolVector()
{
	delete[]bv;
}

BoolVector & BoolVector::operator = (BoolVector &V)
{
	if (this != &V)
	{
		delete[]bv;
		n = V.n;
		m = V.m;
		bv = new UC[m];
		for (int i = 0; i < m; i++)
			bv[i] = V.bv[i];
	}
	return *this;
}

BoolVector & BoolVector::operator = (BoolVector &&V)
{
	if (this != &V) {
		delete[]bv;
		n = V.n;
		m = V.m;
		bv = new UC[m];
		for (int i = 0; i < m; i++)
			bv[i] = V.bv[i];
	}
	return *this;
}

void BoolVector::Output(int N)
{
	int k;
	UC mask = 1;
	if (N >= m || N < 0) cout << "incorrect position";
	else
	if (N == 0) 
	   {
		if (n % 8) k = n % 8 - 1;
		else
			k = 7;
			mask <<= k;
		    for (int i = 0; i <= k; i++)
					if (bv[N] & mask) 
					{
						cout << 1;
						mask >>= 1;
					}
					else 
					{
						cout << 0;
						mask >>= 1;
					}
	   }
			else 
			{
				mask <<= 7;
				for (int i = 0; i < 8; i++)
					if (bv[N] & mask) 
					{
						cout << 1;
						mask >>= 1;
					}
					else 
					{
						cout << 0;
						mask >>= 1;
					}
			}

}

void BoolVector::Print()
{
	for (int i = 0; i < m; i++) 
		(*this).Output(i);
}

BoolVector BoolVector::operator & (BoolVector V) //создается новый вектор
{
	//n1-длина результата, n1=min{n, V.n}
	int n1 = n, i_res = m - 1;
	if (n1 > V.n) 
	{ n1 = V.n; i_res = V.m - 1; }
	int i, i_V;
	BoolVector Res(n1);
	for (i = m - 1, i_V = V.m - 1; i_res >= 0; i--, i_V--, i_res--)
		Res.bv[i_res] = bv[i] & V.bv[i_V];
	return Res;
}

BoolVector & BoolVector::operator &= (BoolVector V) //изменяется *this
{
	BoolVector T;
	T = (*this)&V;
	*this = T;
	return *this;
}

BoolVector BoolVector::operator|(BoolVector V)
{
	int  n1 = n, i_res = m-1;
	if (n1 < V.n)
	{
		n1 = V.n;
		i_res = V.m-1;
	}
	int i, i_V;
	BoolVector Res(n1);
	for (i = m - 1, i_V = V.m - 1; i >= 0 && i_V >= 0; i--, i_V--, i_res--)
		Res.bv[i_res] = bv[i] | V.bv[i_V];
	return Res;
}

BoolVector & BoolVector::operator|=(BoolVector V)
{
	BoolVector T;
	T = (*this) | V;
	*this = T;
	return *this;
}

BoolVector BoolVector::operator^(BoolVector V)
{
	int  n1 = n, i_res = m-1;
	if (n1 < V.n) 
	{
		n1 = V.n;
		i_res = V.m-1;
	}
	int i, i_V;
	BoolVector Res(n1);
	for (i = m - 1, i_V = V.m - 1; i >= 0 && i_V >= 0; i--, i_V--, i_res--)
		Res.bv[i_res] = bv[i] ^ V.bv[i_V];
	return Res;
}

BoolVector & BoolVector::operator ^= (BoolVector V)
{
	BoolVector T;
	T = (*this) ^ V;
	*this = T;
	return *this;
}

BoolVector & BoolVector::operator ~ ()
{
	for (int i = 0; i < m; i++)
		bv[i] = ~bv[i];
	return *this;
}

BoolVector BoolVector::operator >> (int k) //сдвиг вправо
{
	BoolVector Res(n);
	if (k < n)
	{
		int i;
		for (i = 0; i < n - k; i++)
			if(this->operator[](i+k)=='1') Res.SetUp1(i);
			 else Res.SetUp0(i);
	}
	return Res;
}

BoolVector & BoolVector::operator >>= (int k) //изменяется *this сдвиг
{
	BoolVector T;
	T = (*this) >> k;
	*this = T;
	return *this;
}

BoolVector BoolVector::operator << (int k)
{
	BoolVector Res(n);
	if (k < n)
	{
		int i;
		for (i = 0; i < n - k; i++)
			if ((*this)[i] == '1')
				Res.SetUp1(k + i);
			else
				Res.SetUp0(k + i);
	}
	return Res;
}

BoolVector & BoolVector::operator <<= (int k)
{
	BoolVector T;
	T = (*this) << k;
	*this = T;
	return *this;
}

BoolVector BoolVector::SetUp1(int pos)
{
	if (pos >= n) cout << "incorrect position";
	else 
	{
		int m1 = pos / 8, k1 = pos % 8;
		UC mask = 1 << k1;
		bv[m - 1 - m1] |= mask;
	}
	return *this;
}

BoolVector BoolVector::SetUp0(int pos)
{
	if (pos >= n)
		cout << "incorrect position" << endl;
	else
	{
		int m1 = pos / 8, k1 = pos % 8;
		UC mask =(1 << k1);
		mask = ~mask;
		bv[m - 1 - m1] &= mask;
	}
	return *this;
}

BoolVector BoolVector::SetUp1(int kol, int pos)
{
	if (pos >= n || pos + kol > n)
		cout << "incorrect position" << endl;
	else 
	{
		for (int i = pos; i < pos + kol; i++)
			SetUp1(i);
	}
	return *this;
}

BoolVector BoolVector::SetUp0(int kol, int pos)
{
	if (pos >= n || pos + kol >= n)
		cout << "incorrect position" << endl;
	else 
	{
		for (int i = pos; i < pos + kol; i++)
			SetUp0(i);
	}
	return *this;
}

BoolVector BoolVector::Invert(int pos)
{
	if (pos >= n) cout << "incorrect position" << endl;
	else
		if ((*this)[pos] == '0') (*this).SetUp1(pos);
		else (*this).SetUp0(pos);
	return *this;
}

BoolVector BoolVector::Invert(int kol, int pos)
{
	if (pos >= n || pos + kol >= n) cout << "incorrect position" << endl;
	else
		for (int i = 0; i < kol; i++)
			if ((*this)[pos + i] == '0') (*this).SetUp1(pos + i);
			else (*this).SetUp0(pos + i);
	return *this;
}

UC BoolVector::operator [] (int pos)
{
	if (pos >= n) { cout << "incorrect position"; return '0'; }
	else 
	{
		int m1 = pos / 8, k1 = pos % 8;
		UC mask = 1 << k1;
		if (bv[m - 1 - m1] & mask) return '1';
		else return '0';
	}
}

bool BoolVector::operator == (BoolVector V)
{
	for (int i = 0; i < m; i++)
		if (bv[i] != V.bv[i])
			return false;
	return true;
}

bool BoolVector::operator != (BoolVector V)
{
	for (int i = 0; i < n; i++)
		if (bv[i] != V.bv[i])
			return true;
	return false;
}

bool BoolVector::operator < (BoolVector V)
{
	for (int i = 0; i < n; i++)
		if (bv[i] > V.bv[i])
			return false;
	return true;
}

bool BoolVector::operator > (BoolVector V)
{
	for (int i = 0; i < n; i++)
		if (bv[i] < V.bv[i])
			return false;
	return true;
}

void BoolVector::Scan(int N)
{
	cout << "enter bool vector, length " << " " << N;
	char *s;
	s = new char[N + 1];
	gets_s(s, N + 1);
	cout << endl << "b2: ";
	gets_s(s, N + 1);
	BoolVector T(s);
	*this = T;
	delete[]s;
}

int BoolVector::Weight()
{
	int count = 0;
	UC mask = 1;
	for (int j = 0; j < m; j++)
	{
		mask <<= 7;
		for (int i = 0; i < 8; i++)
		{
			if (bv[j] & mask) count ++;
			if (i < 7) mask >>= 1;
		}
	}
	return count;
}

ostream & operator << (ostream & r, BoolVector & V)
{
	V.Print();
	return r;
}

istream & operator >> (istream &r, BoolVector &V)
{
cout << "enter length:";
int N;
cin >> N;
V.Scan(N);
return r;
}
