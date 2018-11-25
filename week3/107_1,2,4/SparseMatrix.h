#pragma once
#include"MatrixTerm.h"

class SparseMatrix
{
public:
	SparseMatrix():rows(0),cols(0),terms(0),smArray(NULL){}
	SparseMatrix(int ,int ,int,MatrixTerm* =NULL);
	~SparseMatrix();
	SparseMatrix FastTranspose();
	SparseMatrix newFastTranspose();
	MatrixTerm Search(int);
	void print();
private:
	int rows, cols, terms, capacity;
		MatrixTerm * smArray;
};

