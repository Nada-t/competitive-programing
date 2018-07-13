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
int v[102][102], vis[102][102], sm = 0;
bool val(int i, int j, int n, int x)
{
	return(i >= 0 && i < n && j >= 0 && j < n && vis[i][j] == 0 && v[i][j] == x);
}

void dfs(int i, int j, int n)
{
	vis[i][j] = 1;
	sm++;
	if (val(i + 1, j, n, v[i][j])) dfs(i + 1, j, n);
	if (val(i - 1, j, n, v[i][j])) dfs(i - 1, j, n);
	if (val(i, j + 1, n, v[i][j])) dfs(i, j + 1, n);
	if (val(i, j - 1, n, v[i][j])) dfs(i, j - 1, n);

}
int  main()
{
	fast();
	int n;
	while (cin >> n && n)
	{
		memset(v, -1, sizeof v);
		memset(vis, 0, sizeof vis);
		vector<pair<int, int>> vv(n + 2);
		vector<vector<int>> a;
		bool o = 0;
		cin.ignore();

		for (int i = 0;i < n - 1;i++)
		{
			string s;
			getline(cin, s);
			s += " ";
			bool b = 0, bb = 0;
			int x = 0, y = 0;
			for (int j = 0;j < s.size();j++)
			{
				if (s[j] == ' ')
				{
					if (!b) b = 1;
					else
					{
						x--, y--;
						v[x][y] = i + 1;
						if (!bb)
						{
							o = 1;
							vv[i] = { x,y };
							bb = 1;
						}
						x = 0, y = 0, b = 0;
					}
				}
				else
				{
					if (!b)
					{
						x *= 10;
						x += (s[j] - '0');
					}
					else
					{
						y *= 10;
						y += (s[j] - '0');
					}
				}
			}
		}
		for (int i = 0;i < vv.size();i++)
		{
			if (vis[vv[i].first][vv[i].second] == 0)
			{
				sm = 0;
				dfs(vv[i].first, vv[i].second, n);
				if (sm < n || sm > n) o = 0;
			}
		}
		bool l = 0, ll = 0;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (v[i][j] == -1 && !ll) ll = 1, dfs(i, j, n);
				if (vis[i][j] == 0)
				{
					l = 1;
					break;
				}
			}
		}

		if (l || (o == 0 && n > 1)) cout << "wrong" << endl;
		else cout << "good" << endl;
	}

}


