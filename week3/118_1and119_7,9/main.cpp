#include<iostream>
#include<Windows.h>
#include"String.h"
using namespace std;

int main()
{
	char a[5] = { 'a','a','a','a','b' }; String a1(a, 5);
	char b[6] = { 'a','b','a','b','a','a' }; String b1(b, 6);
	char c[9] = { 'a','b','a','a','b','a','a','b','b'}; String c1(c, 9);
	char t[3] = { 'a','b','b' }; String t1(t, 3);
	cout << "a: "; a1.print(); cout << endl << "b: "; b1.print(); cout << endl << "c: "; c1.print();cout << endl;
	//No1.
	cout << "the frequency:\na: " << a1.frequency() << "\nb: " << b1.frequency() << "\nc: " << c1.frequency() << endl;
	//No2.
	cout << "the fail array:\na:"; a1.printf();
	cout << endl << "b: "; b1.printf();
	cout << endl << "c: "; c1.printf();
	//No3.
	cout << "find t1(a,b,b)in c:\n" << c1.FastFind(t1) << endl;
	c1.newfail(); cout << "newfailarray of c: \nc: "; c1.printf();
	cout << "use newfailarray in fastfind: " << endl<<c1.FastFind(t1)<<endl;
	int t0 = GetTickCount();
	for (int i = 0; i < 1000000; i++)
		c1.FastFind(t1);
	int t2= GetTickCount();
	c1.newfail();
	int t3= GetTickCount();
	for (int i = 0; i < 1000000; i++)
		c1.FastFind(t1);
	int t4= GetTickCount();
	cout << t2 - t0 <<endl<< t4 - t3;
	system("pause");
}