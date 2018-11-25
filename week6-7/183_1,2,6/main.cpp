//No.1 write function to calculate the length of the list and its complexity
//No.2 write function to delete node from the chain(if x==first,then first should be reset to the point to the first new node)
//No.6 traverse a chain in both directions by reversing the links during the left_to_right traversal.
//     (1)write a function to move pointer r,n nodes to the right from any position (l,r)
//     (2)write a function to move pointer r,n nodes to the left from any position (l,r)
#include<iostream>
#include"LinkedList.h"
using namespace std;


int main()
{
	LinkedList k;
	Node*a = new Node(0), *b = new Node(1), *c = new Node(2),*d=new Node(3),*e=new Node(4),*f=new Node(5);
	k.Add(0, a);
	k.Add(a, b);
	k.Add(b,c);
	k.Add(c, d);
	k.Add(d, e);
	k.Add(e,f);//initialize the list as(0,1,2,3,4);
	cout << "the initial list is: " << endl;
	k.print();
	//No.1:
	cout <<"the length of the list is:\n" <<k.length() << endl;//time complexity is O(n)
	k.Delete(f);
	//No.2:
	cout << "delete f from the list: " << endl;
	k.print();
	//No.3:
	cout << "after travers the list at (c,d): " << endl;
	travers i(c, d);
	k.trav(i);
	k.print(i);
	cout << "move the travers point 1 node on the left direction" << endl;
	k.travl(i, 1);
	k.print(i);
	cout << "move the travers point 2 nodes on the right direction" << endl;
	k.travr(i, 2);
	k.print(i);
	
	system("pause");
}