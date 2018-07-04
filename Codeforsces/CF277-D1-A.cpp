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
bool p = 0;
long long n, m, x, y, sm = 0;
vector<vector<long long>> v;
vector<long long> vis;

void dfs(long long nd)
{
	vis[nd] = 1;

	for (int i = 0;i < v[nd].size();i++)
	{
		long long nx = v[nd][i];
		if (!vis[nx])
		{
			dfs(nx);
			p = 1;
		}
	}
}
int  main()
{

	fast();
	cin >> n >> m;
	v.resize(n + m + 2);
	vis.resize(n + m + 2, 0);

	for (int i = 0;i < n;i++)
	{
		cin >> x;
		while (x--)
		{
			cin >> y;
			v[i + 1].push_back(y + n);
			v[y + n].push_back(i + 1);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		if (!vis[i])
		{
			sm++;
			dfs(i);
		}
	}
	if(p) cout << sm - 1 << endl;
	else cout << sm << endl;
}


