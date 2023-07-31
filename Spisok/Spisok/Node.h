#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Node
{
	int key;
	Node *pred, *next;
public:
	Node()
	{
		key = -1; pred = NULL; next = NULL;
	}
	Node(int k, Node *Pr, Node *Nxt)
	{
		key = k; pred = Pr; next = Nxt;
	}
	int &Key() { return key; }
	friend class List;
};