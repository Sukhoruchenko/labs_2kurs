#pragma once

#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;

template <class T> class Array
{
	 T *a;
    int n;
	void ShiftLeft(int pos);//сдвиг позиции
public:
	Array(int m = 1);//к-р с аргументом по умолчанию
	Array(T *b, int m);//к-р с аргументом массив
	Array(Array <T> &B);//к-р копирования
	~Array();//д-р
	Array <T> operator+(Array <T> &B);
	Array <T> operator+=(Array <T> &B);
	void Scan(int);//ввод массива
	void Print();//вывод массива
	int Find(T key);//поиск элемента в массиве 
	Array <T> & operator=(Array <T> &B);//операция присвоения
	T & operator[](int);//считывание элемента по позиции
	Array <T> & operator+=(int key);//добавление кей в конец массива
	Array <T> & operator+(int key);//создание массива в
	Array <T> & operator-=(int pos);//удаление эл-та с позиции пос
	Array <T> & operator-(T key);//удаление эл-та по ключу
	bool operator==(Array <T>);//проверка равенства
	bool operator!=(Array <T>);//проверка неравенства
	T Min(T *a, int n);//найти минимум в массиве возможно нужно поставить спецификатор типа
	T Max(T *a, int n);//найти максимум в массиве аналогично предположение сверху
	void Sort();//сортировка массива 
	template <class T> friend ostream & operator<<(ostream &r, Array <T> &x);
	template <class T> friend istream & operator>>(istream &r, Array <T> &x);
};

template <class T> Array <T> ::~Array()
{
	delete[] a;
}

template <class T> Array <T> Array <T> ::operator+(Array <T> &B)
{
	int m = n + B.n;
	Array Res(m);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	for (int j = 0, i = n; i < m; i++, j++)
		Res.a[i] = B.a[j];
	return Res;
}

template <class T> Array <T> Array <T> ::operator+=(Array <T> &B)
{
	T *p;
	p = new T[n];
	for (int i = 0; i < n; i++)
		p[i] = a[i];
	int m = n;
	n += B.n;
	delete[]a;
	a = new T[n];
	for (int i = 0; i < m; i++)
		a[i] = p[i];
	for (int j = 0, i = m; i < n; i++, j++)
		a[i] = B.a[j];
	return *this;
}

template <class T> void Array <T> ::Scan(int m)
{
	if (n != m)
	{
		delete[]a;
		n = m;
		a = new T[n];
	}
	cout << "enter" << ' ' << m << ' ' << "elements: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

template <class T> void Array <T> ::Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

template <class T> int Array <T> ::Find(T key)
{
	int i;
	try 
	{
		for (i = 0; i < n; i++) 
		{
			if (a[i] == key)
				return i;
		}
		if (i == n)
		throw "The element is not in the array";
		cout << endl;
	}
	catch (char *S) 
	{
		cout << S;
		return -1;
	}
	catch (...)
	{
		cout << "The element is not in the array";
		cout << endl;
		return -1;
	}
}

template <class T> Array <T> ::Array(int m)
{
	if (m == 0) m = 1;
	if (m < 0) m *= -1;
	n = m;
	a = new T[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}

template <class T> Array <T> ::Array(T *b, int m)
{
	n = m;
	a = new T[n];
	for (int i = 0; i < n; i++) a[i] = b[i];
}

template <class T> Array <T> ::Array(Array <T> &B)
{
	n = B.n;
	a = new T[n];
	for (int i = 0; i < n; i++)
		a[i] = B.a[i];
}

template <class T> Array <T> & Array <T> ::operator=(Array <T> &B)
{
	if (this != &B)
	{
		if (n != B.n)
		{
			delete[] a;
			n = B.n;
			a = new T[n];
		}
		for (int i = 0; i < n; i++)
			a[i] = B.a[i];
	}
	return *this;
}

template <class T> T & Array <T> ::operator[](int pos)
{
	/*if (pos<0 || pos>n)
	{
		cout << "incorrect pos, return a[0]";
		return a[0];
	}
	return a[pos];*/
	try 
	{
		if (pos<0 || pos>n)
			throw "Incorrect index";
	}
	catch (char *S) 
	{
		cout << S;
	}
	return a[pos];
}

template <class T> Array <T> & Array <T> ::operator+=(int key)
{
	T *t = new T[n + 1];
	for (int i = 0; i < n; i++)
		t[i] = a[i];
	t[n] = key;
	delete[] a;
	n++;
	a = t;
	return *this;
}

template <class T> Array <T> & Array <T> ::operator+(int key)
{
	Array Res(n + 1);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	Res.a[n] = key;
	return Res;

}

template <class T> Array <T> & Array <T> ::operator-=(int pos)
{
	ShiftLeft(pos);
	return *this;
}

template <class T> Array <T> & Array <T> ::operator-(T key)
{
	int pos = this->Find(key);
	if (pos != -1)
		this->ShiftLeft(pos);
	else cout << "key is absent" << endl;
	return *this;
	//Array Res = *this;
	//int pos = Res.Find(key);
	//Res.ShiftLeft(pos);
	//return Res;
}

template <class T> bool Array <T> ::operator==(Array <T> B)
{
	if (n == B.n)
	{
		for (int i = 0; i < n; i++)
			if (a[i] != B.a[i]) return false;
		return true;
	}
	return false;
}

template <class T> bool Array <T> ::operator!=(Array <T> B)
{
	if (n == B.n)
	{
		for (int i = 0; i < n; i++)
			if (a[i] != B.a[i]) return true;
		return false;
	}
	return true;

}

template <class T> ostream & operator<<(ostream &r, Array <T> &x)
{
	x.Print();
	return r;
}

template <class T> istream & operator>>(istream &r, Array <T> &x)
{
	int m;
	cout << "enter the number of element ";
	cin >> m;
	if (x.n != m) {
		delete[]x.a;
		x.n = m;
		x.a = new T[m];
	}
	cout << "enter " << m << " elements: ";
	for (int i = 0; i < x.n; i++)
		r >> x.a[i];
	return r;
	
}

template <class T> T Array <T> ::Min(T *a, int n)
{
	T min = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

template <class T> T Array <T> ::Max(T *a, int n)
{
	T max = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

template <class T> void Array <T> ::Sort()
{
	int c, i, m;
	for (c = n; c > 0; c--)
		for (i = 0; i < c - 1; i++)
			if (a[i] > a[i + 1]) 
			{
				m = a[i];
				a[i] = a[i + 1];
				a[i + 1] = m;
			}
}

template <class T> void Array <T> ::ShiftLeft(int pos)
{
	int i;
	if (pos < 0 || pos >= n)
	{
		cout << "incorrect pos" << endl;
		return;
	}
	T *t;
	t = new T[n];
	for (int i = 0; i < n; i++)
		t[i] = a[i];
	delete[]a;
	a = new T[n - 1];
	for (i = 0; i < pos; i++)
		a[i] = t[i];
	for (i = pos + 1; i < n; i++)
		a[i - 1] = t[i];
	delete[]t;
	n--;
}



