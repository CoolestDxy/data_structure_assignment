#include "SparseMatrix.h"
#include<iostream>
using namespace std;


SparseMatrix::SparseMatrix(int r,int c,int t,MatrixTerm* x)
{
	rows = r;
	cols = c;
	terms = t;
	smArray = new MatrixTerm[t];
	if(x!=NULL)
	for (int i = 0; i < t; i++)
	{
		smArray[i] = x[i];
	}
}

SparseMatrix::~SparseMatrix()
{
}

SparseMatrix SparseMatrix::FastTranspose()
{
	int * RowSize = new int[cols];
	int * RowStart = new int[cols];
	SparseMatrix b(cols,rows,terms);
	if (terms > 0)
	{
		for (int i = 0; i < cols; i++)RowSize[i] = 0;
		for (int i = 0; i < terms; i++)RowSize[smArray[i].col]++;

		RowStart[0] = 0;
		for (int i = 1; i < cols; i++)RowStart[i] = RowStart[i - 1] + RowSize[i - 1];

		for (int i = 0; i < terms; i++)
		{
			int j = RowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowStart[smArray[i].col]++;
		}
	}
	delete[]RowSize;
	delete[]RowStart;
	return b;
}

SparseMatrix SparseMatrix::newFastTranspose()
{
	int * RowSizeStart = new int[cols*2];
	SparseMatrix b(cols, rows, terms);

	if (terms > 0)
	{
		for (int i = 0; i < cols*2; i++)RowSizeStart[i] = 0;
		for (int i = 0; i < terms; i++)RowSizeStart[smArray[i].col]++;

		RowSizeStart[terms] = 0;
		for (int i = 1; i < terms; i++)RowSizeStart[i+terms] = RowSizeStart[i - 1+terms] + RowSizeStart[i - 1];

		for (int i = 0; i < terms; i++)
		{
			int j = RowSizeStart[smArray[i].col+terms];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowSizeStart[smArray[i].col+terms]++;
		}
	}
	delete[]RowSizeStart;
	return b;
}
MatrixTerm SparseMatrix::Search(int v)
{
	for (int i = 0; i < terms; i++)
	{
		if (smArray[i].value== v)return smArray[i];

	} cout << "didn't find the value" << endl;
}

void SparseMatrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			bool flag=0;
			for (int k = 0; k < terms; k++)
			{
				if (smArray[k].row == i && smArray[k].col == j)
				{
					cout << ' ' << smArray[k].value << ' '; flag = 1;
				}
			}if(flag==0)cout << " 0 ";
		}
		cout << endl;
	}
}