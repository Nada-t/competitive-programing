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
#include <stdlib.h>
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
vector<vector<int>> v, comp;
vector<int> artp, low, dfn;
vector<pair<int, int>> vp;
int  cdfs = 0, ichd = 0, sm_art = 0;

void tarjan(int nd, int par)
{
	low[nd] = dfn[nd] = ++cdfs;

	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (dfn[nx] == -1)
		{
			if (par == -1) ichd++;
			tarjan(nx, nd);

			if (low[nx] >= dfn[nd]) artp[nd]++;
			if (low[nx] > dfn[nd]) vp.push_back({ min(nd,nx),max(nd,nx) });
			low[nd] = min(low[nd], low[nx]);
		}
		else if (par != nx) low[nd] = min(low[nd], dfn[nx]);
	}
}
void scc()
{
	int n = v.size();
	artp.clear(); artp.resize(n);
	low.clear(); low.resize(n);
	dfn.clear(); dfn.resize(n, -1);
	vp.clear();// vp.resize(n);
	cdfs = 0;

	n--;
	for (int i = 1;i <= n;i++)
	{
		if (dfn[i] == -1)
		{
			ichd = 0;
			tarjan(i, -1);
			if (ichd <= 1) artp[i] = 0;
		}
	}
	sm_art = 0;
	for (int i = 0;i < artp.size();i++)
	{
		if (artp[i] > 0) sm_art++;
	}
	return;
}
int  main()
{
	fast();
	int n, t = 0, k = 0;
	while (cin >> n && n)
	{
		v.clear();
		v = vector<vector<int>>(n + 1);
		string s;
		map<string, int> mp;
		map<int, string> mps;
		vector<string> vs;
		int r;

		if (t > 0)
		{
		    cout << endl;
		}

		for (int i = 0;i < n;i++)
		{
			cin >> s;
			mp[s] = i + 1;
			mps[i + 1] = s;
		}
		cin >> r;
		for (int i = 0;i < r;i++)
		{
			string s1, s2;
			cin >> s1 >> s2;
			int x = mp[s1];
			int y = mp[s2];
			v[x].push_back(y);
			v[y].push_back(x);
		}
		scc();
		cout << "City map #" << ++t << ": " << sm_art << " camera(s) found" << endl;
		for (int i = 0;i < artp.size();i++)
		{
			if (artp[i] > 0) vs.push_back(mps[i]);
		}
		sort(vs.begin(), vs.end());
		k = 0;
		for (int i = 0;i < vs.size();i++)
		{
			cout << vs[i] << endl;
		}

	}
}