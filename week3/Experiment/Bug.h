#pragma once

class Bug
{
public:
	Bug(int,int);
	~Bug();
	void stimulate(int,int);
	void print();
private:
	int **count,n,m,step;
static	int imove[8],jmove[8];
};

