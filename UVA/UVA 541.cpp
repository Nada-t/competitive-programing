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
int  main()
{
	fast();

	int n;
	while (cin >> n && n != 0)
	{
		int a[101][101], sm = 0;
		vector<int> v, vrow, vcol;
		bool b = 0;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				cin >> a[i][j];
				if (a[i][j]) sm++;
			}
			vrow.push_back(sm);
			if (sm % 2 != 0) v.push_back(i + 1);
			sm = 0;
		}
		sm = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (a[j][i]) sm++;
			}
			vcol.push_back(sm);
			if (sm % 2) v.push_back(i + 1);
			sm = 0;
		}
		sm = 0;
		for (int i = 0;i < vrow.size();i++)
		{
			if (vrow[i] % 2) sm++;
			if (sm > 1)
			{
				b = 1;
			}
		}
		sm = 0;
		for (int i = 0;i < vcol.size();i++)
		{
			if (vcol[i] % 2) sm++;
			if (sm > 1)
			{
				b = 1;
			}
		}
		if (b) cout << "Corrupt" << endl;

		else if (v.size() != 0)
		{
			cout << "Change bit (" << v[0] << "," << v[1] << ")" << endl;
		}

		else cout << "OK" << endl;

	}
}