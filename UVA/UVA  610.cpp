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
map<pair<int, int>, int> mpp;
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

			if (low[nx] > dfn[nd])
			{
				vp.push_back({ min(nd,nx),max(nd,nx) });
				vp.push_back({ max(nd,nx),min(nd,nx) });
			}
			else
			{
				if (mpp[{ max(nd, nx), min(nd, nx) }] == 0)
				{
					vp.push_back({ nd,nx });
					mpp[{ max(nd, nx), min(nd, nx) }]++;
				}
			}
			low[nd] = min(low[nd], low[nx]);
		}
		else if (par != nx)
		{
			if (mpp[{ max(nd, nx), min(nd, nx) }] == 0)
			{
				mpp[{ max(nd, nx), min(nd, nx) }]++;
				vp.push_back({ nd,nx });
			}
			low[nd] = min(low[nd], dfn[nx]);
		}
	}
}
void scc()
{
	int n = v.size();
	artp.clear(); artp.resize(n);
	low.clear(); low.resize(n);
	dfn.clear(); dfn.resize(n, -1);
	vp.clear(); mpp.clear();
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
	for (int i = 0;i < vp.size();i++)
	{
		cout << vp[i].first << " " << vp[i].second << endl;
	}
	cout << "#" << endl;
	return;
}
int  main()
{
	fast();
	int n, m, t = 1;
	while (cin >> n >> m && n && m)
	{
		v.clear();
		v = vector<vector<int>>(n + 1);
		cout << t++ << endl << endl;
		for (int i = 0;i < m;i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		scc();
	}
}