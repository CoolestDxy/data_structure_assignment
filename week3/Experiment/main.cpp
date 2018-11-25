//Ğ¡³æÂşÓÎn*m¿é´É×©£¬
#include<iostream>
#include"Bug.h"
using namespace std;

int main()
{
	cout << "for (15,15): " << endl;
	Bug a(15,15);
	a.stimulate(9, 9);
	a.print();
	cout << "for (39,19): " << endl;
	Bug b(39, 19);
	b.stimulate(0, 0);
	b.print();
	system("pause");
}