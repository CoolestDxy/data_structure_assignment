//give the all combinations of n boolean variables and count the frequency
#include <iostream>
using namespace std;
int countture = 0,countfalse=0;

void print(int* p, int length);//用于显示结果
void arrange(int* p, int start, int length);//递归计算所有组合

int main()
{
	int *p;
	int i;
	cout << "input number of variables " << endl;
	cin >> i;
	p = new int[i];
	arrange(p, 0, i);
	cout << "the frequency of false is " << countfalse << endl;
	cout << "the frequency of true is " << countture << endl;
	system("pause");
	return(0);
}

void print(int* p,int length)
{
	for (int k = 0; k < length; k++)
	{
		if (*(p + k) == 0)
		{
			cout << "false, ";
			countfalse++;
		}
		else
		{
			cout << "true,  ";
			countture++;
		}
	}
	cout<<endl;
}

void arrange(int*  p, int start, int length)
{
	int b;
	if (start == length)print(p, length);
	else
		for (b = 0; b <= 1; b++)
		{
			*(p + start) = b;
			arrange(p, start + 1, length);
		}
}