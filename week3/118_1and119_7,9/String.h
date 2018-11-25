#pragma once
class String
{
public:
	String(char *, int m);
	~String();
	int FastFind(String);
	int frequency();
	void fail();
	void printf();
	void print();
	void newfail();
private:
	int length;
	char* s;
	int *f;
};

