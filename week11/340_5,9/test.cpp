//3.write a complete C++function for depth-first search under the assumption that graphs are represented using adjacency lists.Test.
//5.breadth_first search.
#include"Graph.h"
using namespace std;

int main()
{
	Graph g(5);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(0, 4);
	g.addedge(1, 3);
	g.addedge(1, 2);
	g.addedge(2, 4);
	cout << "the adjacency list of graph:" << endl;
	g.print();
	cout << "test for function BFS: " << endl;
	g.BFS();
	cout << "test for function DFS: " << endl;
	g.DFS();
	//g.test();
	system("pause");
}