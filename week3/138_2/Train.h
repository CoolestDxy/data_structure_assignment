#pragma once
class Train
{
public:
	Train() :length(0),top(-1),flag(0){train = new int[10];}
	void set(Train);
	Train(int*,int);
	void run(int);
	void add(int i) { train[++top] = i; }
	void del() {top--; }
	~Train();
private:
	int* train;
	int length,top;
	int flag;
};

