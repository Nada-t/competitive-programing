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

long long n, x, y, w, sn = 0, len = 0, ln = -1;
vector<vector<pair<long long, long long>>> v;
vector<long long> vis;

void dfs(long long nd, long long sm)
{
	vis[nd] = 1;
	len += sm;

	for (int i = 0;i < v[nd].size();i++)
	{
		long long nx = v[nd][i].first;
		long long wn = v[nd][i].second;

		if (!vis[nx]) dfs(nx, wn);
	}
	ln = max(ln, len);
	len -= sm;
}
int  main()
{

	fast();
	cin >> n;
	v.resize(n + 2);
	vis.resize(n + 2, 0);

	for (int i = 0;i < n - 1;i++)
	{
		cin >> x >> y >> w;
		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
		sn += (2 * w);
	}
	dfs(1, 0);

	cout << sn - ln << endl;
}


