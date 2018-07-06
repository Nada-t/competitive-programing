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
long long n, m, x, y, a[100005], sm = 0, mn = 1e9;
vector<vector<long long>> v;
vector<long long> vis;


void dfs(int nd)
{
	vis[nd]++;
	mn = min(mn, a[nd - 1]);
	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (!vis[nx]) dfs(nx);
	}
}
int  main()
{
	fast();
	cin >> n >> m;

	v.resize(n + 2);
	vis.resize(n + 2, 0);

	for (int i = 0;i < n;i++)
		cin >> a[i];

	for (int i = 0;i < m;i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	for (int i = 1;i <= n;i++)
	{
		if (!vis[i])
		{
			mn = 1e9;
			dfs(i);
			sm += mn;
		}
	}

	cout << sm << endl;
}