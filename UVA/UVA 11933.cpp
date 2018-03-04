#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
string bin(int n)
{
	string s = "";
	while (n)
	{
		s += ((n % 2) + '0');
		n /= 2;
	}
	return s;
}
int in(string s)
{
	int x = 0;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] == '1')
		{
			x += pow(2, i);
		}
	}
	return x;
}
int  main()
{
	fast();

	int n;
	while (cin >> n&&n != 0)
	{
		string s = bin(n), sa = "", sb = "";
		bool b = 0;
		
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == '0')
			{
				sa += '0';
				sb += '0';
			}
			else
			{
				if (!b) sa += '1', sb += '0', b = 1;
				else sb += '1', sa += '0', b = 0;
			}
		}
		cout << in(sa) << " " << in(sb) << endl;

	}

}