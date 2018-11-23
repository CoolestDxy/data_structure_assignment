#include<iostream>
#include"Polynomial.h"
#include"term.h"
using namespace std;

int main()
{
	int a[6] = { 3, 2, 1, 2, 1,0 };
	float b[6] = { 1,0,1,0,2,1 };
	Polynomial x1, x2,x3,x4;
	
		x1.input(b, a,3);
		x2.input(b+3, a+3,3);
		cout << "x1:" << endl;
		x1.output();
		cout << "x2:" << endl;
		x2.output();
	cout << endl<<"when x=2 x1 is:" << endl;
	cout << x1.Cal(2) << endl; 
	cout << endl<<"x1 + x2 is:"<<endl;
	x3 = x1.Add(x2);
	x3.output();
	cout <<endl<< "x1 * x2 is :" << endl;
	x4 = x1.Multiple(x2);
	x4.output();
	system("pause");
}