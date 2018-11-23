#include<iostream>
#include <windows.h>  
using namespace std;


int binary_search(int arr[],int	n,int key)
{
	int	left = 0;
	int	right = n - 1;
	while
		(left <= right)
	{
		int	mid = left + ((right - left) >> 1);
		if(arr[mid] > key)
		{
			right = mid - 1;
		}

		else if(arr[mid] < key)
			{
				left = mid + 1;
			}
		else
			{
			return	mid+1;
			}
	}
	return
		-1;
}

int main()
{
	int a[101];
	for (int i = 0; i < 101; i++)
	{
		a[i] = i;
	}
	double t1 = GetTickCount();
	for (int u = 0; u < 1000000; u++)binary_search(a, 101, 1);
	double t2 = GetTickCount();
	cout << "search for 1 1000000 times: "<<(t2-t1)<<endl;//一次查找所需时间
	double t = 0;
	cout << "average time for search from 0 to 100:(s)" << endl;//从0到100进行搜索，每个数搜索1000000次累加时间后计算平均值
	for (int i = 0; i < 101; i++)
	{
		t1 = GetTickCount();
		for (int u = 0; u < 1000000; u++)binary_search(a, 101, 1);
		t2 = GetTickCount();
		t += t2 - t1;
	}
	t/= 101000000000;
	cout << t;
	system("pause");
}