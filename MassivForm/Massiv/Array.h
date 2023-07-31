#pragma once

#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

using namespace std;

class Aarray
{
	int *a, n;
	void ShiftLeft(int pos);//сдвиг позиции
public:
	Aarray(int m = 1);//к-р с аргументом по умолчанию
	Aarray(int *b, int m);//к-р с аргументом массив
	Aarray(Aarray &);//к-р копирования
	~Aarray();//д-р
	Aarray RandMas(int p);
	Aarray operator+(Aarray &B);
	Aarray operator+=(Aarray &B);
	void Scan(int);//ввод массива
	void Print();//вывод массива
	int Find(int key);//поиск элемента в массиве 
	Aarray & operator=(Aarray &);//операция присвоения
	int & operator[](int);//считывание элемента по позиции
	Aarray & operator+=(int key);//добавление кей в конец массива
	Aarray & operator+(int key);//создание массива в
	Aarray & operator-=(int pos);//удаление эл-та с позиции пос
	Aarray & operator-(int key);//удаление эл-та по ключу
	bool operator==(Aarray);//проверка равенства
	bool operator!=(Aarray);//проверка неравенства
	int Min(int *a, int n);//найти минимум в массиве
	int Max(int *a, int n);//найти максимум в массиве
	void Sort();//сортировка массива 
	friend ostream & operator<<(ostream &r, Aarray &x);
	friend istream & operator>>(istream &r, Aarray &x);
};
