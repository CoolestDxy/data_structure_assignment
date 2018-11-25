//No.3:write a C++ function to copy the elements of a chain into an array
//No.4:Write a C++ function to compute the expression the sum for i=1 to i=n-5:(xi*...x(i+5))
#include<iostream>
#include <algorithm>
#include"ChainIterator.h"
#include"Chain.h"
using namespace std;

void mycopy(ChainIterator<int> start, ChainIterator<int>end, int*y)
{
	while (start != end)
	{
		*y = start.current->data; start++; y++;
	}
	*y = start.current->data;
}

void copy1(Chain<int>x, int *y)
{
	ChainIterator<int>tf, tl;
	tf.current = x.first;
	tl.current= x.first;
	int l=0;
	while (tl.current->link!= 0)
	{

		tl.current=tl.current->link; l++;
	}
	mycopy(tf, tl,y);
}


int compute(Chain<int> x)
{
	ChainIterator<int>f, l,temp;
	int sum = 0,t2=1;
	f.current=l.current = x.first;
	temp = f;
	for (int i = 0; i < 4; i++)
	{
		l++;
	}
	while(l.current != 0)
	{
		t2 = 1;
		while (temp != l)
		{
			t2*= temp.current->data;
			temp++;
		}
		t2*= temp.current->data;
		sum += t2;
		f++; l++;
		temp = f;
	}
	return sum;
}

int main()
{
	Chain<int> k;
	ChainNode<int>*a = new ChainNode<int>(1), *b = new ChainNode<int>(1), *c = new ChainNode<int>(2), *d = new ChainNode<int>(3), *e = new ChainNode<int>(4), *f = new ChainNode<int>(5);
	k.Add(0, a);
	k.Add(a, b);
	k.Add(b, c);
	k.Add(c, d);
	k.Add(d, e);
	k.Add(e, f);//initialize the list as(0,1,2,3,4);
	
	int*t = new int[6];
	copy1(k, t);
	cout << "copy the chain to the int array:" << endl;
	for (int i = 0; i < 6; i++)
		cout << " " << t[i] << " ";
	cout << endl<<"after compute :" << endl;
	cout <<compute(k)<<endl;
	system("pause");
}