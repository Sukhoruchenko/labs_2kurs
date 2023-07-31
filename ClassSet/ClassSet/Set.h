#pragma once

#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

#include "BoolVector.h"

using namespace std;

class Set : public BoolVector
{
	int M; 	 //кол-во элементов мн-ва

public:
	Set();
	Set(char *s);
	Set(Set &);
	Set & operator = (Set &);
	~Set() {};
	Set operator + (char ch);// добавление эл-та к мн-ву  (создается новое мн-во)
	Set & operator += (char ch);// добавление эл-та к мн-ву (меняется *this)
	Set operator + (Set S);// объединение мн-в (создается новое мн-во)
	Set & operator += (Set S);// объединение мн-в (меняется *this)
	Set operator - (char ch);// удаление эл-та из мн-ва (создается новое мн-во)
	Set & operator -= (char ch);// удаление эл-та из мн-ва (меняется *this)
	Set operator - (Set S);// разность мн-в (создается новое мн-во)
	Set & operator -= (Set S);// разность мн-в (меняется *this)
	Set operator * (Set S);//пересечение мн-в (создается новое мн-во)
	Set  operator *= (Set S);//объединение мн-в (меняется *this)
	Set operator ~ ();//дополнение до универсального - универсальное мн-во - мн-во из 256 символов
	bool operator == (Set S);//равенство мн-в
	bool operator != (Set S);//неравенство мн-в
	int Number() { return M; }
	char Max();
	virtual void Scan(int);
	virtual void Print();
	friend ostream & operator<< (ostream &r, Set &S);
	friend istream & operator>> (istream &r, Set &S);
};


