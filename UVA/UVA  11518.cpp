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
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
void dfs(int nd, vector<vector<int>> &v, vector<int> &vis)
{
	vis[nd] = 1;

	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (!vis[nx])
		{
			dfs(nx, v, vis);
		}
	}
}
int  main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, l, sm = 0;
		cin >> n >> m >> l;
		vector<vector<int >> v(n + 1);
		vector<int> vis(n + 1, 0);

		for (int i = 0;i < m;i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
		}

		for (int i = 0;i < l;i++)
		{
			int x;
			cin >> x;
			dfs(x, v, vis);
		}
		for (int i = 1;i <= n;i++)
		{
			//cout << vis[i] << "  ";
			if (vis[i]) sm++;
		}
		cout << sm << endl;
	}
}