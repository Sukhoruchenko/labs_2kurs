#pragma once

#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

#include "BoolVector.h"

using namespace std;

class Set : public BoolVector
{
	int M; 	 //���-�� ��������� ��-��

public:
	Set();
	Set(char *s);
	Set(Set &);
	Set & operator = (Set &);
	~Set() {};
	Set operator + (char ch);// ���������� ��-�� � ��-��  (��������� ����� ��-��)
	Set & operator += (char ch);// ���������� ��-�� � ��-�� (�������� *this)
	Set operator + (Set S);// ����������� ��-� (��������� ����� ��-��)
	Set & operator += (Set S);// ����������� ��-� (�������� *this)
	Set operator - (char ch);// �������� ��-�� �� ��-�� (��������� ����� ��-��)
	Set & operator -= (char ch);// �������� ��-�� �� ��-�� (�������� *this)
	Set operator - (Set S);// �������� ��-� (��������� ����� ��-��)
	Set & operator -= (Set S);// �������� ��-� (�������� *this)
	Set operator * (Set S);//����������� ��-� (��������� ����� ��-��)
	Set  operator *= (Set S);//����������� ��-� (�������� *this)
	Set operator ~ ();//���������� �� �������������� - ������������� ��-�� - ��-�� �� 256 ��������
	bool operator == (Set S);//��������� ��-�
	bool operator != (Set S);//����������� ��-�
	int Number() { return M; }
	char Max();
	virtual void Scan(int);
	virtual void Print();
	friend ostream & operator<< (ostream &r, Set &S);
	friend istream & operator>> (istream &r, Set &S);
};


