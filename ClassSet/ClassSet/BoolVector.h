#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

typedef unsigned char UC;

class BoolVector
{
  protected:
	UC *bv;
	int n, m;
	int Input(char*, int, int, int); //������������� ��-�� ������� bv
  public:
	BoolVector();
	BoolVector(int N);
	BoolVector(char*s);
	BoolVector(char *s, int N); //strlen(s)!=N
	BoolVector(BoolVector &);
	~BoolVector();
	BoolVector & operator = (BoolVector&);
	void Print();
	void Scan(int);
	int Weight();
	BoolVector  operator & (BoolVector); //��������� ����� ������
	BoolVector & operator &= (BoolVector); //���������� *this
	BoolVector  operator | (BoolVector); //��������� ����� ������
	BoolVector & operator |= (BoolVector); //���������� *this
	BoolVector  operator ^ (BoolVector); //��������� ����� ������
	BoolVector & operator ^= (BoolVector); //���������� *this
	BoolVector & operator ~ ();
	BoolVector  operator >> (int); //��������� ����� ������
	BoolVector & operator >>= (int); //���������� *this
	BoolVector operator << (int); //��������� ����� ������
	BoolVector & operator <<= (int); //���������� *this
	BoolVector  SetUp1(int);
	BoolVector  SetUp0(int);
	BoolVector SetUp1(int kol, int pos);
	BoolVector SetUp0(int kol, int pos);
	BoolVector Invert(int);
	BoolVector Invert(int kol, int pos);
	UC operator [] (int);
	bool operator == (BoolVector);
	bool operator != (BoolVector);
	bool operator < (BoolVector);  //x<y ���� x[i]<=y[i] ��� ���� i
	bool operator > (BoolVector);  //x>y ���� x[i]>=y[i] ��� ���� i
	friend ostream & operator << (ostream &r, BoolVector &V);
	friend istream & operator >> (istream &r, BoolVector &V);
};
