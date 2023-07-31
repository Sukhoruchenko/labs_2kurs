#pragma once

#include "Node.h"

class List
{
	Node *head, *tail;
public:
	List();
	List(int n); //формирует список из n случайных чисел
	List(int *a, int n); //формирует список из массива n чисел
	List(List &);
	~List();
	List & operator = (List &);
	void AddAfter(int k, Node *pr); //добавление узла после pr
	void AddToHead(int k);  //добавление эл-та в голову
	void AddToTail(int k);  //добавление эл-та в хвост
	void AddAfter(List S, Node *pr); //добавление списка S после pr
	void AddToHead(List);  //добавление списка в голову
	void AddToTail(List);  //добавление списка в хвост
	void Del(Node *p); //удаление узла p
	void DelHead();    //удаление головы
	void DelTail();    //удаление хвоста
	Node *FindKey(int k); //поиск по ключу
	Node *FindPos(int pos); //поиск по позиции
	bool Empty();
	bool NotEmpty();
	void Clear();  //очистка списка, т.е удаляем все, кроме фиктивных головы и хвоста
	bool operator == (List);//
	bool operator != (List);//
	Node *Max();  //нахождение max эл-та списка
	Node *Min();  //нахождение min эл-та списка
	void Scan(int);
	void Print();
	friend ostream &operator << (ostream &r, List &S);
	friend istream &operator >> (istream &r, List &S);

};
