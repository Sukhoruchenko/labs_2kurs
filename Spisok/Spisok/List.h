#pragma once

#include "Node.h"

class List
{
	Node *head, *tail;
public:
	List();
	List(int n); //��������� ������ �� n ��������� �����
	List(int *a, int n); //��������� ������ �� ������� n �����
	List(List &);
	~List();
	List & operator = (List &);
	void AddAfter(int k, Node *pr); //���������� ���� ����� pr
	void AddToHead(int k);  //���������� ��-�� � ������
	void AddToTail(int k);  //���������� ��-�� � �����
	void AddAfter(List S, Node *pr); //���������� ������ S ����� pr
	void AddToHead(List);  //���������� ������ � ������
	void AddToTail(List);  //���������� ������ � �����
	void Del(Node *p); //�������� ���� p
	void DelHead();    //�������� ������
	void DelTail();    //�������� ������
	Node *FindKey(int k); //����� �� �����
	Node *FindPos(int pos); //����� �� �������
	bool Empty();
	bool NotEmpty();
	void Clear();  //������� ������, �.� ������� ���, ����� ��������� ������ � ������
	bool operator == (List);//
	bool operator != (List);//
	Node *Max();  //���������� max ��-�� ������
	Node *Min();  //���������� min ��-�� ������
	void Scan(int);
	void Print();
	friend ostream &operator << (ostream &r, List &S);
	friend istream &operator >> (istream &r, List &S);

};
