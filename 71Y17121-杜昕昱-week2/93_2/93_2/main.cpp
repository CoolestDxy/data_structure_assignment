#include<iostream>
using namespace std;

struct Linear
{
	int *a;
	int num;
};

int comp(struct Linear a, struct Linear b)
{
	for (int j = 0; j < a.num; j++)cout << *(a.a+ j);
	cout << endl;
	for (int j = 0; j < b.num; j++)cout << *(b.a + j);
	cout << endl;
	for (int k = 0; k < a.num&&k < b.num; k++)
	{
		if (*(a.a + k) == *(b.a + k))continue;
		else if (*(a.a + k) < *(b.a + k))return -1;
		else return 1;
	}
	if (a.num < b.num)return -1;
	else if (a.num > b.num)return 1;
	else return 0;
}

int main()
{
	int a[5] = { 1,2,3,4,5 };
	int b[6] = { 1,2,3,4,5,6};
	int c[4] = { 1,2,3,6 };
	struct Linear x1 = { a,5 }, x2 = { a,5 }, x3 = { b,6 }, x4 = {c,4};
	cout << comp(x1, x2) << endl;
	cout << comp(x1, x3) << endl;
	cout<< comp(x1, x4)<<endl;
	cout << comp(x3, x2)<<endl;
	system("pause");
	return 0;
}