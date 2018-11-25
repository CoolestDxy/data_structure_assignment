//1.�����ҵ��������ض�ֵ����ʱ��
//2.����fasttranspose�㷨ʱ��ռ�����
//4.��дfasttranspose�㷨��һ�����鴢��rowsize��rowstart
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
	cout << "No2:discuss the time and storage requirements of fastTranspose\n" << "����ת���㷨�볣��ת���㷨�ıȽϣ�\n����ת����ʱ�临�Ӷ���Ҫ������ͨת�÷���\n" <<
		"���ڿռ临�Ӷ������ڿ���ת�÷����ȳ��淽�������������鴢��rowsize��rowstart���Բ����糣���㷨\n" <<
		"���ϣ������׷�������㷨����ô�ض�Ҫ�ڿռ临�Ӷ�������������" << endl<<endl;
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