//develop a polynomial by list and do following request:
//each polynomial is to be represented as a circular list with a head node
//use an available-space list
//1.operator>>
//2.operator<<
//3.copy constructor
//4.operator==
//5.operator+
//6.operator-
//7.operator*
//8.calculate
#include<iostream>
#include"Polynomial.h"
using namespace std;

int main()
{
	Polynomial test1;
	cin >> test1;
	Polynomial test2,t;
	cout << "test2" << endl;
	cin >> test2;
	cout <<"test1:\n" <<test1<<"test2:\n"<< test2<<endl;
	t = test1 + test2;
	cout << "test1 plus test2: \n"<<t<<endl;
	t = test1 - test2;
	cout << "test1 minus test2:\n" << t << endl;
	t = test1 * test2;
	cout << "test1 multiply test2:\n"  << t<< endl;
	int num;
	cout << "input the x:\n";
	cin >> num;
	cout << "the test1:\n"<<test1.Cal(num)<<endl<<"the test2:\n"<<test2.Cal(num);
	system("pause");

}