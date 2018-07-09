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
void sol(long long nd, vector<vector<long long>> &v, vector<long long> &vis, long long x)
{
	queue<int> q;
	q.push(nd);
	vis[nd] = nd;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0;i < v[node].size();i++)
		{
			int nx = v[node][i];
			if (!vis[nx])
			{
				vis[nx] = node;
				q.push(nx);
			}
		}
	}
}
void print(int x, vector<long long> &vis)
{
	if (vis[x] == x) return;
	print(vis[x], vis);
	cout << vis[x] << " ";
}
int  main()
{
	fast();
	int n;
	while (cin >> n)
	{
		long long m;
		vector<vector<long long>> v(n + 1);

		string s;
		for (int i = 0;i < n;i++)
		{
			cin >> s;
			s += ",";
			int d = 0, x = 0;
			for (int j = 0;j<s.size();j++)
			{
				if (isdigit(s[j]))
				{
					d *= 10;
					d += (s[j] - '0');
				}
				else if (s[j] == '-') d = 0;
				else if (s[j] == ',')
				{
					v[i + 1].push_back(d);
					d = 0;
				}
			}
		}

		cin >> m;
		cout << "-----" << endl;

		while (m--)
		{
			long long r, l;
			vector<long long> vis(n + 1, 0);

			cin >> l >> r;

			sol(l, v, vis, r);

			if (vis[r] == 0) cout << "connection impossible";
			else
			{
				print(r, vis);
				cout << r;
			}
			cout << endl;
		}
	}
}