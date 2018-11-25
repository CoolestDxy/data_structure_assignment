//write a function to concatenate the two lists *this and
//m.On conpletion of the function,the resulting list
//should be stored in *this and the list m should contain
//the empty list.Run in O(1)time;
#include<iostream>
#include"DblList.h"
using namespace std;

int main()
{
	DblList list1,list2;
	int i;
	for ( i = 0; i < 5; i++)
	{
		list1.Add(new DblListNode(i));
	}
	for (; i < 9; i++)
	{
		list2.Add(new DblListNode(i));
	}
	cout << "list1:" << endl;
	list1.print();
	cout << "list2:" << endl;
	list2.print();
	cout << "concatenate:" << endl;
	list1.Concatenate(list2);
	system("pause");
}