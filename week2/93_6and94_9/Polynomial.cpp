#include "Polynomial.h"
#include"term.h"
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int Polynomial::capacity = 100;
term *Polynomial::termArray=new term[100];
int Polynomial::free = 0;

Polynomial::Polynomial()
	:Start(free),Finish(free-1)
{
}

float Polynomial::Cal(int x)
{
	float c = 0;
	for (int i = Start; i <= Finish; i++)
	{
		c+=termArray[i].coef*pow(x, termArray[i].exp);
	}
	return c;
}

void Polynomial::New(float c,int e)
{
	if (free >= capacity) {
		capacity *= 2;
		term* temp = new term[capacity];
		for (int i = 0; i < capacity / 2; i++)
			temp[i]= termArray[i];
		termArray = temp;
		delete temp;
	}
	termArray[free].coef = c;
	termArray[free].exp = e;
	free++;
}

void Polynomial::input(float* c,int* e,int n)
{
	Start = free;
	for(int i=0;i<n;i++)
	{
		New(c[i], e[i]);
	}

	Finish = free-1;
}

void Polynomial::output()
{
	int i;
	for (i = Start; i < Finish; i++)
	{
		if (termArray[i].coef == 0)continue;
		cout << termArray[i].coef << "x^" << termArray[i].exp<<'+';
	}
	cout << termArray[i].coef << "x^" << termArray[i].exp << endl;
}

Polynomial Polynomial::Add(Polynomial B)
{
	Polynomial C;
	int a = Start; int b = B.Start;
	C.Start = free; float c;
	while ((a<=Finish)&&(b<=B.Finish))
	{
		switch (compare(termArray[a].exp, termArray[b].exp))
		{
		case 0:
			c = termArray[a].coef + termArray[b].coef;
			if (c)New(c, termArray[a].exp);
			a++; b++;
			break;
		case -1:
			New(termArray[b].coef, termArray[b].exp);
			b++;
			break;
		case 1:
			New(termArray[a].coef, termArray[a].exp);
			a++;
			break;
		}
		
	}for (; a <= Finish; a++)
			New(termArray[a].coef, termArray[a].exp);
		for (; b <= Finish; b++)
			New(termArray[b].coef, termArray[b].exp);
		C.Finish = free - 1;
	return C;
}

Polynomial Polynomial::Multiple(Polynomial B)
{
	Polynomial C;
	C.Start = free;
	for(int i=Start;i<Finish+1;i++)
		for (int j = B.Start; j < B.Finish+1; j++)
		{
			int t1 = termArray[i].exp+termArray[j].exp;
			float t2 = termArray[i].coef*termArray[j].coef;
			bool flag = 0;
			for (int o = C.Start; o <free; o++)
			{
				if (termArray[o].exp == t1)
				{
					flag = 1;
					termArray[o].coef += t2;
				}
			}
			if (flag == 0)New(t2, t1);
		}
	C.Finish = free - 1;
	return C;
}

Polynomial::~Polynomial()
{
}
