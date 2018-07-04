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

void dfs(int n, vector<vector<int>> &v, vector<int> &vis, int &sm, int x)
{
	vis[n] = x;
	sm++;
	for (int i = 0;i < v[n].size();i++)
	{
		int nx = v[n][i];
		if (vis[nx] != x)
		{
			dfs(nx, v, vis, sm, x);
		}
	}

}
int  main()
{
	int t, z = 0;
	cin >> t;
	while (t--)
	{
		int n, ans , mx = 0, sm = 0;
		cin >> n;

		vector<vector<int>> vv(n + 1);
		vector<int> vis(n + 1, 0);
		map<int, int> mp;

		for (int i = 0;i < n;i++)
		{
			int u, v;
			cin >> u >> v;
			vv[u].push_back(v);
		}

		for (int i = 1;i <= n;i++)
		{
			if (!vis[i])
			{
				sm = 0;
				vis[i] = i;
				dfs(i, vv, vis, sm, i);
				if (sm > mx)
				{
					mx = sm;
					ans = i;
				}
			}
		}
		cout << "Case " << ++z << ": " << ans << endl;
	}
}