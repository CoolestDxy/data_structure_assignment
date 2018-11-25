#include "String.h"
#include<iostream>
using namespace std;

String::String(char*init, int m)
{
	s = new char[m]; length = m;
	f = new int[m];
	for (int i = 0; i < m; i++)
	{
		s[i] = init[i];
	}
	fail();
}


String::~String()
{
}

int String::frequency()
{
	int c = 0;
	for (int i = 0; i < length; i++)
	{
		bool flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (s[i] == s[j])flag = 1;
		}
		if (flag == 0)c++;
	}
	return c;
}

int String::FastFind(String pat)
{

	int posp = 0, poss = 0;
	int lp = pat.length, ls = length;
	while ((posp < lp) && (poss < ls))
	{
		if (pat.s[posp] == s[poss])
		{
			posp++; poss++;
		}
		else if (posp == 0)poss++;
		else posp = pat.f[posp - 1] + 1;
	}
	if (posp < lp)return-1;
	else return poss - lp;
}

void String::fail()
{
	f[0] = -1;
	for (int j = 1; j < length; j++)
	{
		int i = f[j - 1];

		while((*(s + j) != *(s + i + 1)) && (i >= 0))i = f[i];
		if (*(s + j) == *(s + i + 1))f[j] = i + 1;
		else f[j] = -1;
	}
}

void String::newfail()
{
	f[0] = -1;
	for (int j = 1; j < length; j++)
	{
		int i = f[j - 1];
		while ((*(s + j) != *(s + i + 1)) && (i >= 0))i = f[i];
		if (*(s + j) == *(s + i + 1)&& *(s + j+1) == *(s + i + 2))f[j] = i + 1;
		else f[j] = -1;
	}
}

void String::printf()
{
	for (int i = 0; i < length; i++)
		cout << ' ' << f[i] << ' '; cout << endl;
}

void String::print()
{
	for (int i = 0; i < length; i++)
		cout << ' ' << s[i] << ' '; cout << endl;
}