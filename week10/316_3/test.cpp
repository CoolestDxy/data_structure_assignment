//experimentally compare the performance of simpleunion and simplefind with weightunion and collapsingfind.for this ,generate a random sequence of union and find operations
#include<iostream>
#include"Sets.h"
using namespace std;

int main()
{
	Sets set;
	set.buildfortest();
	srand(time(0));
	float t1 = GetTickCount();
	for (int i = 0; i < 10000000; i++)
		set.Simplefind(rand() % 12 - 1);
	float t2 = GetTickCount();
	cout <<"the simplefind for 10000000 times:\n"<< t2 - t1 << endl;
	t1 = GetTickCount();
	for (int i = 0; i < 10000000; i++)
		set.CollapsingFind(rand() % 12 - 1);
	 t2 = GetTickCount();
	 cout << "the collapdingfind 10000000 times:\n" << t2- t1 << endl;//可见，collapsing效率更高一点
	 system("pause");
}