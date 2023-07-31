#include"List.h"
#include <iostream>

using namespace std;

void main()
{
	List S1;
	S1.AddToHead(1);
	S1.AddToTail(10);
	cout << "S1: ";
	S1.Print();
	cout << endl;
	List S2(5);
	cout << "S2: " << S2 << endl;
	Node* j;
	j = S2.Max();
	cout << "Max in S2: " << j->Key() << endl;
	j = S2.Min();
	cout << "Min in S2: " << j->Key() << endl;
	j = S2.FindPos(2);
	cout << "2 element S2:  ";
	if (j == NULL) cout << "not element" << endl;
	else cout << j->Key() << endl;
	cout << "6 element in S2:  ";
	j = S2.FindPos(6);
	if (j == NULL) cout << "not element" << endl;
	else cout << j->Key() << endl;
	S2.DelTail();
	cout << "S2: " << S2 << endl;
	List S3 = S1;
	cout << "S3: " << S3 << endl;
	cout << " S3=S1 ?: ";
	if (S3 == S1) cout << "Yes" << endl;
	else cout << "Not" << endl;
	cout << "S3.FindKey(15):  ";
	j = S3.FindKey(15);
	if (j == NULL) cout << " not element " << endl;
	else cout << "15 element in S3: " << j->Key() << endl;
	S3.DelHead();
	if (j == NULL) cout << " elementa not na this pos " << endl;
	if (j != 0) S3.Del(j); 
	cout << "S3: " << S3 << endl;
	S3.DelTail();
	if (j == NULL) cout << " elementa not na this pos " << endl;
	if (j != 0) S3.Del(j);
	cout << "S3: " << S3 << endl;
	if (S3.Empty() == 0) cout << "empty" << endl;
	else cout << "S3 not empty" << endl;
	int a[6];
	for (int i = 0; i < 6; i++)
		a[i] = rand() % 20;
	List S4(a, 6);
	cout << "S4: " << S4 << endl;
	j = S4.FindKey(2);
	if (j == 0) S4.AddToHead(2);
	else S4.Del(j);
	cout << "S4: " << S4 << endl;
	List S5 = S2;
	cout << "S5: " << S5 << endl;
	cout << " element 4 in S5? ";
	j = S5.FindKey(4);
	if (j == 0) cout << "absent"<<endl;
	else cout << "yes " <<  endl;
	if (j == 0) S5.AddToTail(4);
	else S5.Del(j);
	cout << "S5: " << S5 << endl;
	S5.Clear();
	S5.Scan(4);
	S5.AddToTail(S4);
	cout << "S5.AddToTail(S4): " << S5 << endl;
	S5.AddToHead(S1);
	cout << "S5.AddToHead(S1):  " << S5 << endl;
	cout << "S5: " << S5 << endl;
	_getch();
}