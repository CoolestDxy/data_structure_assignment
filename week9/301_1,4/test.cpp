//1.write C++ class definations for winner and loser tree
//4.write a function to construct a loser tree for k records.Use position 0 of your loserTree array ti store a pointer to the overall winner.
//Show that this construction can be carried out in time O(k).Assume that k is a power of 2.
#include"LoserTree.h"
#include"WinnerTree.h"
using namespace std;
int main()
{	
	WinnerTree win(8);
	int a[8] = { 1,2,3,4,5,6,7,8 };
	cout << "the leaves(competetors) are: " << endl;
	for (int i = 0; i < 8; i++)
		cout << a[i] << ' ';
	cout << endl << "\ntest for WinnerTree ;\nthe winner leave is: ";
	win.init(a);
	cout << win.getwinner()<<endl;
	LoserTree lose(8);
	lose.init(a);
	cout <<endl<<"test for LoserTree: \nthe loser leave is: "<< lose.getloser() << endl;
	cout <<"the winner leave is: "<< lose.getwinner()<<endl;
	system("pause");
}
