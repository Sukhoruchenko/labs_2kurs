#pragma once

#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

using namespace std;

typedef unsigned char UC;

#include "BoolVector.h"

class BoolMatrix
{
	BoolVector *BV;
	int m, n;   //m - ���-�� ����� �������, n - ���-�� ��������
	int Max(char **s, int M);  //��������������� �-�
public:
	BoolMatrix();
	BoolMatrix(int, int);
	BoolMatrix(char **s, int M);
	BoolMatrix(BoolMatrix &);
	BoolMatrix & operator= (BoolMatrix &);
	~BoolMatrix() { delete[]BV; }
	void Scan(int, int);
	void Print();
	BoolVector & operator[] (int);
	bool  operator== (BoolMatrix);
	bool operator!= (BoolMatrix);
	BoolMatrix SetUp1(int i, int j); //���������� � 1 ��-� [i][j]
	BoolMatrix SetUp0(int i, int j); //�������� � 0 ��-� [i][j]
	BoolMatrix SetUp1(int kol, int i, int pos); //���������� � 1 kol ��-��� � i-� ������, ������� � ������� pos
	BoolMatrix SetUp0(int kol, int i, int pos); //���������� � 0 kol ��-��� � i-� ������, ������� � ������� pos
	BoolMatrix Invert(int i, int j); //������������� ��-� [i][j]
	BoolMatrix Invert(int kol, int i, int pos); //������������� kol ��-��� � i-� ������, ������� � ������� pos
	BoolMatrix operator & (BoolMatrix &X); //���������� ���������� ������, ��������� ����� �������  
	BoolMatrix & operator &= (BoolMatrix &X); //���������� ���������� ������, ���������� *this
	BoolMatrix operator | (BoolMatrix &X); //���������� ��������� ������, ��������� ����� �������  
	BoolMatrix & operator |= (BoolMatrix &X); //���������� ���������� ������, ���������� *this 
	BoolMatrix operator ^ (BoolMatrix &X); //���������� XOR ������, ��������� ����� �������  
	BoolMatrix & operator ^= (BoolMatrix &X); //���������� XOR ������, ���������� *this
	BoolMatrix operator ~ (); //�������� �������, ���������� *this
	BoolMatrix ShiftRight(int i, int kol); //����� ������ ��-��� i  ������ �� kol ��-���, ��������� ����� �������
	BoolMatrix  & ShiftRightEq(int i, int kol); //����� ������ ��-��� i  ������ �� kol ��-���, ���������� *this
	BoolMatrix ShiftLeft(int i, int kol); //����� ����� ��-��� i  ������ �� kol ��-���, ��������� ����� �������
	BoolMatrix & ShiftLeftEq(int i, int kol); //����� ����� ��-��� i  ������ �� kol ��-���, ���������� *this
	BoolVector Conj(); //���������� ���� ����� �������
	BoolVector Disj(); //���������� ���� ����� �������
	BoolVector Xor(); //XOR ���� ����� �������
	friend ostream &operator << (ostream &r, BoolMatrix & X);
	friend istream &operator >> (istream &r, BoolMatrix & X);
};