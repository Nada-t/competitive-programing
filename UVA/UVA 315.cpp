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
int  cdfs = 0, ichd = 0;

void tarjan(int nd ,int par)
{
	low[nd] = dfn[nd] = ++cdfs;

	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (dfn[nx] == -1)
		{
			if (par == -1) ichd++;
			tarjan(nx, nd);

			if (low[nx] >= dfn[nd] ) artp[nd]++;
			if (low[nx] > dfn[nd]) vp.push_back({ nd,nx });
			low[nd] = min(low[nd], low[nx]);
		}
		else if (par != nx) low[nd] = min(low[nd], dfn[nx]);
	}
}
void scc()
{
	int n = v.size() ;
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
	int sm_art = 0;
	for (int i = 0;i < artp.size();i++)
	{
		if (artp[i] > 0) sm_art++;
	}
	cout << sm_art << endl;
	return;
}
int  main()
{
	fast();
	int n;
	while (cin >> n && n)
	{
		v.clear();
		v = vector<vector<int>>(n + 1);
		string ss;
		
		while (getline(cin, ss) && ss != "0")
		{
			ss += ' ';
			int x = 0, y = 0;
			for (int i = 0;i < ss.size();i++)
			{
				if (ss[i] != ' ')
				{
					y *= 10;
					y += ss[i] - '0';
				}
				else
				{
					if (!x)
					{
						x = y;
					}
					else if (y != 0)
					{
						v[x].push_back(y);
						v[y].push_back(x);
					}
					y = 0;
				}
			}
		}
		scc();
	}
}