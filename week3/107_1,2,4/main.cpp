//1.计算找到矩阵中特定值所用时间
//2.讨论fasttranspose算法时间空间消耗
//4.重写fasttranspose算法用一个数组储存rowsize和rowstart
#include<iostream>
#include<Windows.h>
#include"SparseMatrix.h"
#include"MatrixTerm.h"
using namespace std;

int main()
{
	MatrixTerm a[3] = { MatrixTerm(0,0,1),MatrixTerm(1,1,2),MatrixTerm(2,2,3) };
	SparseMatrix b(4, 5, 3, a);
	//No1
	double t1 = GetTickCount();
	MatrixTerm c;
	for(int i=0;i<1000000;i++)
	c= b.Search(2);
	double t2 = GetTickCount();
	cout << "No1:calculate the running time of finding a value\nfing the coordinate" << endl;
	c.print();
	cout << endl<<"the running time :" << (t2 - t1) / 1000000000 << endl<<endl;
	//No2
	cout << "No2:discuss the time and storage requirements of fastTranspose\n" << "快速转置算法与常规转置算法的比较：\n快速转置在时间复杂度上要优于普通转置方法\n" <<
		"但在空间复杂度上由于快速转置方法比常规方法多了两个数组储存rowsize和rowstart所以并不如常规算法\n" <<
		"综上，如果想追求更快的算法，那么必定要在空间复杂度上做出牺牲。" << endl<<endl;
	//No4
	cout << "No.4:write a new fasttranspose where use only one array to store Rowsize and Rowstart:\n give the matrix:" << endl;
	b.print();
	SparseMatrix d(b.FastTranspose());
	cout << "FastTranspose:" << endl;
	d.print();
	SparseMatrix e(b.newFastTranspose());
	cout << "newFastTranspose:" << endl;
	e.print();
	system("pause");
}