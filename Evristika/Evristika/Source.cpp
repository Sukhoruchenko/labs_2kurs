#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 
#include <string.h> 

using namespace std;

void RandMatr(int **a, int **b, int n)
{
	for (int j = 0; j < n; j++)
				a[0][j] = j;
			for (int i = 0; i < n; i++)
				a[i][0] = i;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
		{
			if (i == j)
			{
				a[i][j] = 0;
				b[i][j] = 0;
			}
			else
			{
				a[i][j] = rand() % 10 + 1;
				b[i][j] = a[i][j];
			}
		}
}

void Print(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++, printf("\n"))
		for (j = 0; j < n; j++)
			printf("%4d", a[i][j]);

}

void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "->" << a[i];
}

int Min(int **a, int n, int i, int min, int t)
{                                                 
	int   j;                                     										
	for (j = 1; j < n; j++)                          
		if (min > a[i][j] && a[i][j] != 0)   
		{
			min = a[i][j];
			t = j;
		}
	return t;                                 
}

void Obnulenie(int **a, int n, int i, int j) 
{
	for (int k = 1, l = 1; k < n, l < n; k++, l++)     
	{
		a[i][k] = 0;  
		a[l][j] = 0;
	}
}

int Cost(int **a, int *p, int n)
{
	int cost = 0, i;
	for (i = 0; i < n - 1; i++)
		cost += a[p[i]][p[i + 1]];
	cost += a[p[n - 1]][p[0]];
	return cost;
}

void main()
{
	int n, **matr1, **matr2, i, j, l, k, *p, MinCost, min, t; // matr2 - подсчет стоимости, matr1 - вывод изменений
	cout << "Input kol-vo city: ";                            //t - номер столбца, в котором находитс первый ненулевой элемент
	cin >> n;                                                 //min - собственно, первый ненулевой элемент
	p = new int[n];
	matr1 = new int*[n];
	for (i = 0; i < n; i++)
		matr1[i] = new int[n];
	matr2 = new int*[n];
	for (i = 0; i < n; i++)
		matr2[i] = new int[n];
	RandMatr(matr1, matr2, n);
	Print(matr1, n);
	cout << endl << "Input city: ";
	cin >> k;
	for (i = 0; i < n; i++)  
		matr1[i][k] = 0;
	cout << endl;
	Print(matr1, n);
	p[0] = k; // подсчет стоимости
	for (int flag = 0; flag < n - 1; flag++) 
	{
		for (i = 1; i < n; i++) 
			for (j = 1; j < n; j++)
				if (matr1[i][j] != 0)
				{
					min = matr1[i][j];
					t = j;
				}
		l = Min(matr1, n, k, min, t); //номер столба минимального элемента строки
		cout << endl;
		matr1[l][k] = 0; 
		Obnulenie(matr1, n, k, l); 
		Print(matr1, n);
		k = l;  
		cout << endl << "City = " << k << endl;
		p[flag + 1] = k; // заполнение последовательности
	}
	cout << endl << "Route: "; Output(p, n-1); 
	MinCost = Cost(matr2, p, n);
	cout << endl << "MinCost = " << MinCost << endl;
	delete[]p;
	for (i = 0; i < n; i++)
		delete[]matr2[i];
	delete[]matr2;
	for (i = 0; i < n; i++)
		delete[]matr1[i];
	delete[]matr1;
	_getch();
}