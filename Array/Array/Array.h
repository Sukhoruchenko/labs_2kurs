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
	void ShiftLeft(int pos);//����� �������
    public:
	Array(int m = 1);//�-� � ���������� �� ���������
	Array(int *b, int m);//�-� � ���������� ������
	Array(Array &);//�-� �����������
	~Array();//�-�
	Array operator+(Array &B);
	Array operator+=(Array &B);
	void Scan(int);//���� �������
	void Print();//����� �������
	int Find(int key);//����� �������� � ������� 
	Array & operator=(Array &);//�������� ����������
	int & operator[](int);//���������� �������� �� �������
	Array & operator+=(int key);//���������� ��� � ����� �������
	Array & operator+(int key);//�������� ������� �
	Array & operator-=(int pos);//�������� ��-�� � ������� ���
	Array & operator-(int key);//�������� ��-�� �� �����
	bool operator==(Array);//�������� ���������
	bool operator!=(Array);//�������� �����������
	int Min(int *a, int n);//����� ������� � �������
	int Max(int *a, int n);//����� �������� � �������
	void Sort();//���������� ������� 
	friend ostream & operator<<(ostream &r, Array &x);
	friend istream & operator>>(istream &r, Array &x);
};


