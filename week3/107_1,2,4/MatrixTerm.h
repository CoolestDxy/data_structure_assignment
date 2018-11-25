#pragma once
#include"SparseMatrix.h"
#include<iostream>
using namespace std;
class SparseMatrix;
class MatrixTerm
{
	friend class SparseMatrix;
public:
	MatrixTerm():row(0), col(0), value(0)
	{}
	MatrixTerm(int x, int y, int z)
	:row(x),col(y),value(z)
	{
	}
	void print()
	{
		cout << row << ',' << col << endl;
}
//	~MatrixTerm();
private:
	int row, col, value;
};

