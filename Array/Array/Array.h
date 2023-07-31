#pragma once
#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;
class Array
{
	int *a, n;
	void ShiftLeft(int pos);//сдвиг позиции
    public:
	Array(int m = 1);//к-р с аргументом по умолчанию
	Array(int *b, int m);//к-р с аргументом массив
	Array(Array &);//к-р копирования
	~Array();//д-р
	Array operator+(Array &B);
	Array operator+=(Array &B);
	void Scan(int);//ввод массива
	void Print();//вывод массива
	int Find(int key);//поиск элемента в массиве 
	Array & operator=(Array &);//операция присвоения
	int & operator[](int);//считывание элемента по позиции
	Array & operator+=(int key);//добавление кей в конец массива
	Array & operator+(int key);//создание массива в
	Array & operator-=(int pos);//удаление эл-та с позиции пос
	Array & operator-(int key);//удаление эл-та по ключу
	bool operator==(Array);//проверка равенства
	bool operator!=(Array);//проверка неравенства
	int Min(int *a, int n);//найти минимум в массиве
	int Max(int *a, int n);//найти максимум в массиве
	void Sort();//сортировка массива 
	friend ostream & operator<<(ostream &r, Array &x);
	friend istream & operator>>(istream &r, Array &x);
};


