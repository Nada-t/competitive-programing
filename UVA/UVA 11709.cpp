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
vector<int> inst, low, dfn, com;
stack<int> st;
int  cdfs = 0;

void tarjan(int nd)
{
	low[nd] = dfn[nd] = cdfs++;
	inst[nd] = 1;
	st.push(nd);

	for (int i = 0;i < v[nd].size();i++)
	{
		int nx = v[nd][i];
		if (dfn[nx] == -1)
		{
			tarjan(nx);
			low[nd] = min(low[nd], low[nx]);
		}
		else if (inst[nx])
		{
			low[nd] = min(low[nd], dfn[nx]);
		}
	}
	if (low[nd] == dfn[nd])
	{
		vector<int> vv;
		int idx = -1;
		while (idx != nd)
		{
			idx = st.top();
			st.pop();
			vv.push_back(idx);
			inst[idx] = 0;
			vv.push_back(idx);
			com[idx] = (comp.size()) ;
		}
		comp.push_back(vv);
	}
}
void scc()
{
	int n = v.size();

	inst.clear(); inst.resize(n);
	low.clear(); low.resize(n);
	dfn.clear(); dfn.resize(n, -1);
	cdfs = 0;

	com.clear(); com.resize(n);
	comp.clear();

	for (int i = 0;i < n;i++)
	{
		if (dfn[i] == -1) tarjan(i);
	}
	return;
}
void compgraph()
{
	int sz = comp.size();

}
int  main()
{
	fast();
	int n;
	while (cin >> n &&n)
	{
		int m;cin >> m;
		v.clear();
		v = vector<vector<int>>(n);
		cin.ignore();
		map<string, int> mp;

		for (int i = 0;i < n;i++)
		{
			string s;
			getline(cin, s);
			mp[s] = i;
		}
		string s, ss;
		for (int i = 0;i < m*2;i++)
		{
			if (i % 2 == 0) getline(cin, s);
			else
			{
				getline(cin, ss);
				v[mp[s]].push_back(mp[ss]);
			}
			
		}
		scc();
		cout << comp.size() << endl;
	}
}