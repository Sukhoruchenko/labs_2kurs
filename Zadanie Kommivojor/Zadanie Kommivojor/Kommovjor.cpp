#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <time.h>
#include<locale>
#include <iostream>

using namespace std;

void Obnulenie(int **a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		a[i][i] = 0;
}

void Invert(int *p, int n, int i)//инвертирует хвост перестановки
{
	int j = i + 1, k = n - 1;
		for (; j < k ; j++, k--)
			{
				int c = p[j];
				p[j] = p[k];
				p[k] = c;
			}
}

void RandMatr(int **a, int m, int n)//создает матрицу случайных чисел, по диагонали -1
{
	/*int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (i == j) a[i][j] = -1;
			else a[i][j] = rand() % 10;*/
	int i, j,c;
	for (j = 0; j < m; j++)
		a[0][j] = j;

	for (i = 0; i < m; i++)
		a[i][0] = i;

	for (i = 1; i < m; i++)
		for (j = 1; j < n; j++) {
			c = rand() % 10;
			if (c != 0)
				a[i][j] = c;
			else
				a[i][j] = c + 1;
		}
}

void PrintMatr(int **a, int m, int n)//вывод матрицы
{
	int i, j;
	for (i = 0; i < m; i++, printf("\n"))
		for (j = 0; j < n; j++)
			printf("%6d", a[i][j]);
}

void Output(int *a, int n)//вывод массива
{
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);
}

int Cost(int **m, int *p, int n)// подсчет стоимости перестановки
{
	int cost = 0, i;
	for (i = 0; i < n - 1; i++)
		cost += m[p[i]][p[i + 1]];
	cost += m[p[n - 1]][p[0]];
	return cost;
}

bool Permutation(int *p, int n)//функция, определяющая след. подстановку
{
	int i, j, k, c, flag = 0;
	for (k = n - 2; k > 0 && flag == 0; k--)
		if (p[k] < p[k + 1]) {
			flag = 1;
			i = k;
			for (j = n - 1; j > i; j--)
				if (p[i] < p[j])
				{
					c = p[i]; p[i] = p[j]; p[j] = c;
					Invert(p, n, i);
					break;
				}
		}
	if (flag != 0) return true;
	return false;
}



void main()
{
	int n, m, k, mincost, i, c, j, *p,**matr,*Pmin;
	cout << "input kol-vo cities: ";
	cin >> n;
	m = n;
	p = new int[n];
	Pmin = new int[n];
	matr = new int*[n];
	for (i = 0; i < n; i++)
		matr[i] = new int[n];
	RandMatr(matr, m, n);
	PrintMatr(matr, m, n);
	Obnulenie(matr, n);
	printf("\n");
	PrintMatr(matr, m, n);
	cout << "Input city: ";
	cin >> k;
	p[0] = k;
	for (i = 1, j = 1; i < n; i++, j++)
	{
		if (i <= k ) p[i] =Pmin[i]= j - 1;
		else p[i]=Pmin[i]= j;
	}
	cout << "First perestanovka: ";
	Output(p, n);
	printf("\n");
	mincost = Cost(matr, p, n);
	cout << "First Cost = "<<mincost<<endl;
	for (i = 1; Permutation(p, n); i++)
	{
		cout << i << ") ";
		Output(p, n);
		c = Cost(matr, p, n);
		cout << " cost=" << c << endl;
		if (c < mincost) {
			mincost = c;
			for (j = 0; j < n; j++)
				Pmin[j] = p[j];
		}
	}
	Output(Pmin,n);
	printf("\n");
	cout << "Min cost= " << mincost<<endl;
	delete[] p;
	delete[] Pmin;
	for (i = 0; i < n; i++)
		delete []matr[i];
	delete[] matr;
	_getch();
}