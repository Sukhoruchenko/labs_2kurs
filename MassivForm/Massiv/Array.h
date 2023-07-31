#pragma once

#include <math.h> 
#include <locale>
#include <conio.h>
#include <iostream>

using namespace std;

class Aarray
{
	int *a, n;
	void ShiftLeft(int pos);//����� �������
public:
	Aarray(int m = 1);//�-� � ���������� �� ���������
	Aarray(int *b, int m);//�-� � ���������� ������
	Aarray(Aarray &);//�-� �����������
	~Aarray();//�-�
	Aarray RandMas(int p);
	Aarray operator+(Aarray &B);
	Aarray operator+=(Aarray &B);
	void Scan(int);//���� �������
	void Print();//����� �������
	int Find(int key);//����� �������� � ������� 
	Aarray & operator=(Aarray &);//�������� ����������
	int & operator[](int);//���������� �������� �� �������
	Aarray & operator+=(int key);//���������� ��� � ����� �������
	Aarray & operator+(int key);//�������� ������� �
	Aarray & operator-=(int pos);//�������� ��-�� � ������� ���
	Aarray & operator-(int key);//�������� ��-�� �� �����
	bool operator==(Aarray);//�������� ���������
	bool operator!=(Aarray);//�������� �����������
	int Min(int *a, int n);//����� ������� � �������
	int Max(int *a, int n);//����� �������� � �������
	void Sort();//���������� ������� 
	friend ostream & operator<<(ostream &r, Aarray &x);
	friend istream & operator>>(istream &r, Aarray &x);
};
