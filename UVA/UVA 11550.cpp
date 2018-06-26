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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		bool b = 0, a[8][30];
		map<pair<int, int>, int> mp;

		cin >> n >> m;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				cin >> a[i][j];
			}
		}

		for (int i = 0;i < m;i++)
		{
			int sm = 0;
			pair <int, int> p;
			for (int j = 0;j < n;j++)
			{
				if (a[j][i])
				{
					sm++;
					if (sm == 1) p.first = j;
					if (sm == 2) p.second = j;
				}
				
			}
			if (sm != 2) b = 1;
			else
			{
				if (mp[p] != 0) b = 1;
				else mp[p]++;
			}
		}
		if (b) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
}