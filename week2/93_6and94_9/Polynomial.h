#pragma once
#include"term.h"

class term;
class Polynomial
{
	friend term;
public:
	Polynomial();
	~Polynomial();
	float Cal(int);
	void New(float, int);
	int compare(int x, int y) {
		if (x < y)return -1;
		else if (x > y)return 1;
		else if(x==y)return 0;
	}
	Polynomial Add(Polynomial);
	Polynomial Multiple(Polynomial);
	void input(float*, int*,int);
	void output();
private:
	static term *termArray;
	static int capacity;
	static int free;
	int Start, Finish;
};

