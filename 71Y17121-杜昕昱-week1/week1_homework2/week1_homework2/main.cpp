//subsets
//���Ȿ���Ϻ���һ����һ���ģ���Ϊ��һ����1��0��Ӧ�ľ��Ǵ������ĸ��λ�ã����Կ��԰�0��1������ĸ�Ƿ���ʾ�ı�־��ֻ��Ķ�print��������
#include <iostream>
using namespace std;

char al[5] = { 'a','b','c','d','e' };

void print(int* p, int length);//������ʾ���
void arrange(int* p, int start, int length);//�ݹ�����������

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