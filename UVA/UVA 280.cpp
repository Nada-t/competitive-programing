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

void dfs(int n, vector<vector<int>> &v, vector<int> &vis)
{
	for (int i = 0;i < v[n].size();i++)
	{
		int nx = v[n][i];
		if (vis[nx] == 0)
		{
			vis[nx] = 1;
			dfs(nx, v, vis);
		}
	}
}
int  main()
{
	int n;
	while (cin >> n && n)
	{
		vector<vector<int>> v(n + 2);
		int x, y, k;
		bool b = 0, b1 = 0;
		while (cin >> y)
		{
			if (!y)
			{
				b = 0;
				if (!b1) break;
				b1 = 0;
				continue;
			}
			if (!b)
			{
				x = y;
				b = 1;
				continue;
			}
			v[x].push_back(y); b1 = 1;
		}
		int m;
		cin >> m;
		while (m--)
		{
			int sm = 0, z;
			vector<int> vv;
			vector<int> vis(n + 2, 0);

			cin >> z;
			dfs(z, v, vis);

			for (int i = 1;i <= n;i++)
			{
				if (!vis[i])
				{
					sm++;
					vv.push_back(i);
				}
			}
			cout << sm;

			for (int i = 0;i < vv.size();i++)
				cout << " " << vv[i];
			cout << endl;

		}
	}
}