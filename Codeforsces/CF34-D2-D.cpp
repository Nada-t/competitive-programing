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
int n, r1, r2, x;
vector<vector<int>> v;
vector<int> vis;
map<int, int> mp;

void dfs(int nd)
{
	vis[nd]++;
	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (!vis[nx])
		{
			mp[nx] = nd;
			dfs(nx);
		}
	}
}
int  main()
{
	fast();
	cin >> n >> r1 >> r2;

	v.resize(n + 2);
	vis.resize(n + 2, 0);
	for (int i = 0;i < n;i++)
	{
		if (i + 1 == r1) continue;
		cin >> x;
		v[x].push_back(i + 1);
		v[i + 1].push_back(x);
	}
	dfs(r2);
	for (auto& it : mp)
	{
		if (it.second != 0) cout << it.second << " ";
	}
}
