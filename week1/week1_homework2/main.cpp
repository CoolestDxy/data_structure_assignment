//subsets
//此题本质上和上一题是一样的，因为上一题中1和0对应的就是此题的字母的位置，所以可以把0与1当作字母是否显示的标志，只需改动print函数即可
#include <iostream>
using namespace std;

char al[5] = { 'a','b','c','d','e' };

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
	system("pause");
	return(0);
}

void print(int* p, int length)
{		cout << "{ ";
	for (int k = 0; k < length; k++)
	{

		if (*(p + k) == 1)
		{
			cout << al[k]<<',';
		}

	}
		cout << " }"<< endl;
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