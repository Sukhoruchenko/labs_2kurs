#include "List.h"

using namespace std;

List::List()
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
}

List::List(int n) //формирует список из n случайных чисел
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	int x, i;
	for (i = 0; i < n; i++)
	{
		x = rand() % 10 + 10;
		AddToTail(x);
	}
}

List::List(int *a, int n) //формирует список из массива n чисел
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	int i;
	for (i = 0; i < n; i++)
		AddToTail(a[i]);
}

List::List(List &S)
{
	head = new Node;
	tail = new Node(-1, head, NULL);
	head->next = tail;
	Node *t = S.head->next;
	while (t != S.tail)
	{
		AddToTail(t->key);
		t = t->next;
	}
}

List::~List()
{
	Clear();
	delete head;
	delete tail;
}

List & List::operator = (List &S)
{
	if (this != &S)
	{
		Clear();
		Node *t = S.head->next;
		while (t != S.tail)
		{
			AddToTail(t->key);
			t = t->next;
		}
	}
	return *this;
}

void List::AddAfter(int k, Node *pr) //добавление узла после pr
{
	Node *t = new Node(k, pr, pr->next);
	pr->next = t;
	t->next->pred = t;
}

void List::AddToHead(int k)
{
	AddAfter(k, head);
}

void List::AddToTail(int k)
{
	AddAfter(k, tail->pred);
}

void List::AddAfter(List S, Node * pr)
{
	Node* t = S.head->next;
	while (t != S.tail)
	{
		AddAfter(t->key, pr);
		pr = pr->next;
	}
}

void List::AddToHead(List S)
{
	Node* t = S.head->next;
	while (t != S.tail)
	{
		AddToHead(t->key);
		t = t->next;
	}
}

void List::AddToTail(List S)
{
	Node* t = S.head->next;
	while (t != S.tail)
	{
		AddToTail(t->key);
		t = t->next;
	}
}

void List::Del(Node *p) //удаление узла p
{
	p->pred->next = p->next;
	p->next->pred = p->pred;
	delete p;
}

void List::DelHead()
{
	Del(head->next); 
}

void List::DelTail()
{
	Del(tail->pred);
}

Node* List::FindKey(int k)
{
	if (head == NULL)
			{
				puts("list is empty");
				return NULL;
			}
	else
	{
		Node* t = head->next;
		while (t != tail && t->key != k)
			t = t->next;
		if (t == tail)
		{
			cout << "No find " << endl;
			return 0;
		}
		else return t;
	}
}

Node* List::FindPos(int pos)
{
	int count = 0;
	Node* t = head->next;
	while (t != tail && count != pos)
	{
		t = t->next; 
		count++;
	}
	if (t == tail)
	{
		cout << "Neverno position " << endl;
		return 0;
	}
	else return t;

}

bool List::Empty()
{
	if (head == NULL) return true;
	return false;
}

bool List::NotEmpty()
{
	if (head != NULL) return true;
	return false;
}

void List::Clear()
{
	while (head->next != tail) DelHead();
}

bool List::operator==(List S)
{
	Node *t = head->next;
	Node *g = S.head->next;
	if (t == tail && g == S.tail)
	{
		cout << "Both empty" << endl;
			return true;
	}
	else if (t != tail && g != S.tail)
			{
				while (t->key == g->key && t != tail && g != S.tail)
				{
					t = t->next; g = g->next;
				}
				if (t == tail && g == S.tail) return true;
				else return false;
			}
	else return false;
}

bool List::operator!=(List S)
{
	Node *t = head->next;
	Node *g = S.head->next;
	if (t == tail && g == S.tail)
	{
		cout << "Both empty" << endl;
		return false;
	}
	else if (t != tail && g != S.tail)
	{
		while (t->key == g->key && t != tail && g != S.tail)
		{
			t = t->next; g = g->next;
		}
		if (t == tail && g == S.tail) return false;
		else return true;
	}
	else return true;
}

Node * List::Max()  //нахождение max эл-та списка
{
	Node *Max = 0, *t = head->next;
	if (t != tail) { Max = t; t = t->next; }
	while (t != tail)
	{
		if (Max->key < t->key) Max = t;
		t = t->next;
	}
	return Max;
}

Node * List::Min()
{
	Node *Min = 0, *t = head->next;
	if (t != tail) { Min = t; t = t->next; }
	while (t != tail)
	{
		if (Min->key > t->key) Min = t;
		t = t->next;
	}
	return Min;
}


void List::Scan(int n)
{
	cout << "enter " << n << " elements of list: ";
	Clear();
	int x, i;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		AddToTail(x);
	}
}

void List::Print()
{
	Node *t = head->next;
	while ((t->next) != NULL)
	{
		cout << t->key << ' ';
		t = t->next;
	}
}

ostream & operator<<(ostream &r, List &S)
{
	S.Print();
	return r;
}

istream &operator>> (istream &r, List &S)
{
	cout << "enter number of elements: ";
	int n;
	cin >> n;
	S.Scan(n);
	return r;
}