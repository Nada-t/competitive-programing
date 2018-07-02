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

int n, ans = 1, sm;
vector<vector<int>> v;
vector<int> vis, a;
map<int, int> mp;

void bfs(int nd)
{
	sm = 0;
	queue<int> q;
	q.push(nd);
	vis[nd] = 1;
	mp[nd] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0;i < v[node].size();i++)
		{
			int nx = v[node][i];
			if (!vis[nx])
			{
				q.push(nx);
				vis[nx] = 1;
				mp[nx] = (mp[node] + 1);
				sm = max(sm, mp[nx]);
			}
		}
	}
}
int  main()
{
	fast();
	cin >> n;

	v.resize(n + 2);
	vis.resize(n + 2, 0);
	
	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;

		if (x > 0)
		{
			v[x].push_back(i + 1);
		}
		else a.push_back(i + 1);
	}

	for (int i = 0;i <a.size();i++)
	{
		if (!vis[a[i]])
		{
			bfs(a[i]);
			ans = max(ans, sm);
		}
	}

	cout << ans << endl;
}