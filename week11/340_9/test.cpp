//write a C++ function to input the number of vertices and edegs in an undirected graph.Next,input the edges one by one and to set up
//the linked adjacency-list representation of the graph.You may assume that no edge is input twice.What is the run time of your function
//as a function of the number of vertices and the number of edges;
#include"Graph.h"
using namespace std;

int main()
{
	cout << "input the number of the vertices:" << endl;
	int i;
	cin >> i;
	cout << endl;
	Graph g(i);
	g.input();//the complexity of function is O(n*e);
	g.print();
	system("pause");
}