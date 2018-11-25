#pragma once
#include<iostream>
#include"List.h"
#include"Node.h"
#include <math.h>

using namespace std;
struct Term
{
	Term(int c=0, int e=0) { coef = c; exp = e; }
	int coef;
	int exp;
	Term Set(int c, int e) { coef = c; exp = e; return *this; }
};

class Polynomial
{
	friend istream& operator >> (istream& is, Polynomial&x)
	{
		cout << "input the number of the term" << endl;
		int i,c,e;
		Term t;
		Node<Term>*temp;
		is >> i;
		for (int k = 0; k < i; k++)
		{
			is >> c >> e;
			t.coef = c;
			t.exp = e;
			temp = new Node<Term>(t);
			x.poly.Add(temp);
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Polynomial&x)
	{
		Node<Term>* temp = x.poly.first->link;
		while (temp->link !=x.poly.first)
		{
			os<< " " << temp->data.coef<<"x^"<<temp->data.exp << "+ ";
			temp = temp->link;
		}
		os << " " << temp->data.coef << "x^" << temp->data.exp <<endl;
		return os;
	}
	friend	Polynomial operator+(const Polynomial&a, const Polynomial&b)
	{
		Polynomial c;
		Node<Term>*p = a.poly.first->link, *q = b.poly.first->link,*temp;
		while (p != a.poly.first&&q != b.poly.first)
		{
			if (p->data.exp > q->data.exp)
			{
				temp = new Node<Term>;
				temp->data.coef= p->data.coef;
				temp->data.exp = p->data.exp;
				c.poly.Add(temp);
				p = p->link;
			}
			else if (p->data.exp == q->data.exp)
			{
				temp = new Node<Term>;
				temp->data.coef = p->data.coef+ q->data.coef;
				temp->data.exp = p->data.exp;
				c.poly.Add(temp);
				p = p->link;
				q = q->link;
			}
			else
			{
				temp = new Node<Term>;
				temp->data.coef = q->data.coef;
				temp->data.exp = q->data.exp;
				c.poly.Add(temp);
				q = q->link;
			}
		}
			while (q != b.poly.first)
			{
				temp = new Node<Term>;
				temp->data.coef = q->data.coef;
				temp->data.exp = q->data.exp;
				c.poly.Add(temp);
				q = q->link;
			}
			while (p != a.poly.first)
			{
				temp = new Node<Term>;
				temp->data.coef = p->data.coef;
				temp->data.exp = p->data.exp;
				c.poly.Add(temp);
				p = p->link;
			}
		return c;
	}
	friend	Polynomial operator-(const Polynomial&a, const Polynomial&b)
	{
		Polynomial c;
		Node<Term>*p = a.poly.first->link, *q = b.poly.first->link, *temp;
		while (p != a.poly.first&&q != b.poly.first)
		{
			if (p->data.exp > q->data.exp)
			{
				temp = new Node<Term>;
				temp->data.coef = p->data.coef;
				temp->data.exp = p->data.exp;
				c.poly.Add(temp);
				p = p->link;
			}
			else if (p->data.exp == q->data.exp)
			{
				temp = new Node<Term>;
				temp->data.coef = p->data.coef - q->data.coef;
				temp->data.exp = p->data.exp;
				if(temp->data.coef!=0)
				c.poly.Add(temp);
				p = p->link;
				q = q->link;
			}
			else
			{
				temp = new Node<Term>;
				temp->data.coef =-q->data.coef;
				temp->data.exp = q->data.exp;
				c.poly.Add(temp);
				q = q->link;
			}
		}
		while (q != b.poly.first)
		{
			temp = new Node<Term>;
			temp->data.coef = q->data.coef;
			temp->data.exp = q->data.exp;
			c.poly.Add(temp);
			q = q->link;
		}
		while (p != a.poly.first)
		{
			temp = new Node<Term>;
			temp->data.coef = p->data.coef;
			temp->data.exp = p->data.exp;
			c.poly.Add(temp);
			p = p->link;
		}
		return c;
	}
	friend	Polynomial operator*(const Polynomial&a, const Polynomial&b)
	{
		Polynomial c,t,innitial;
		Node<Term>*p = a.poly.first->link, *q = b.poly.first->link, *temp,*temp1;
		while (p != a.poly.first)
		{	
			t = innitial;
			q = b.poly.first->link;
			while (q!=b.poly.first) 
			{
				temp = new Node<Term>;
				temp->data.coef = p->data.coef* q->data.coef;
				temp->data.exp = p->data.exp+ q->data.exp;
				temp1 = t.poly.first->link; int flag = 0;
				while (temp1 != t.poly.first)
				{
					if (temp->data.exp == temp1->data.exp) { 
						flag = 1;
						temp1->data.exp += temp->data.exp;
						delete temp;
						break;
					}
					temp1 = temp1->link;
				}
				if (flag == 0) { t.poly.Add(temp); }
				q = q->link;
			}
			c = c + t;
			p = p->link;
		}
		return c;
	}
public:
	Polynomial() { List<Term>poly;}
	Polynomial(const Polynomial&a)
	{
		Node<Term>*temp= a.poly.first->link;
		while (temp != a.poly.first)
		{
			Node<Term>*t = poly.GetNode();
			t->data = temp->data;
			poly.Add(t);
			temp = temp->link;
		}
	}	
	~Polynomial()
	{
		poly.~List();
	}
	const Polynomial&operator=(const Polynomial&a)
	{
		Node<Term>*temp = poly.first->link,*t2;
		while (temp!=poly.first )
		{
			t2 = temp;
			temp=temp->link;
			poly.RetNode(t2);

		}
		poly.first->link = poly.first;
		temp = a.poly.first->link;
		while (temp!= a.poly.first)
		{
			Node<Term>*t = poly.GetNode();
			t->data = temp->data;
			poly.Add(t);
			temp = temp->link;
		}
		return *this;
	}

	int Cal(int x)
	{
		int sum = 0;
		Node<Term>*temp=poly.first->link;
		while (temp != poly.first)
		{
			sum += temp->data.coef*pow(x, temp->data.exp);
			temp = temp->link;
		}
		return sum;
	}

private:
	List<Term>poly;
};

