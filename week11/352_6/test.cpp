//Show how to modify fubctions DFS , as it is used in Components,to produce a list of all newly visited vertices.
#include"Graph.h"
using namespace std;

int main()
{
	Graph g(5);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(1, 2);
	g.addedge(3, 4);
	g.Components();
	system("pause");
}