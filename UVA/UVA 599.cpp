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
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

bool b = 0;

void dfs(int n,vector<vector<int>> &v,map<int ,int> &vis)
{
	if (vis[n]) return;
	vis[n] = 1;
	
	for (int i = 0;i < v[n].size();i++)
	{
		int c = v[n][i];
		b = 1;
		dfs(c, v, vis);
	}
}
int  main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		int sm = 0, sm2 = 0;
		string s, sv;
		map<char, int> mp;
		map<int, int> vis;
		vector<vector<int>> v(27);

		while (cin >> s)
		{
			if (s[0] == '*') break;
			v[s[1] - 'A'].push_back(s[3] - 'A');
			v[s[3] - 'A'].push_back(s[1] - 'A');
			mp[s[3]]++; mp[s[1]]++;
		}
		cin.ignore();
		getline(cin, sv);

		for (int i = 0;i < sv.size();i++)
		{
			if (sv[i] != ',')
			{
				if (mp[sv[i]] == 0)
				{
					sm2++;
					continue;
				}
				if (vis[sv[i] - 'A'] == 0)
				{
					sm++;
					dfs(sv[i] - 'A', v, vis);
				}
			}
		}
		
		cout << "There are " << sm << " tree(s) and " << sm2 << " acorn(s)." << endl;
	}
}