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

int n, m, a[100][100], sm = 0;

int stoint(string s)
{
	int n;
	stringstream ss(s);
	ss >> n;
	return n;
}

bool valid(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == -1);
}

void sol(int x, int y)
{
	if (x + 1 == n && y + 1 == m)
	{
		sm++;
		return;
	}
	a[x][y] = 1;

	if (valid(x, y + 1)) sol(x, y + 1);
	if (valid(x + 1, y)) sol(x + 1, y);
	
	a[x][y] = -1;
	return;
}

int  main()
{
	fast();
	int t, b = 0;
	cin >> t;
	while (t--)
	{
		if (b == 0) b++;
		else cout << endl;

		string s, st = "";
		int  r, x = 0;
		memset(a, -1, sizeof a);

		cin >> n >> m;
		for (int i = 0;i <= n;i++)
		{
			getline(cin, s);
			int r = -1;
			st = "";
			for (int j = 0;j < s.size();j++)
			{
				if (s[j] == ' ')
				{
					if (!st.empty()) x = stoint(st);
					if (r < 0) r = x;
					else a[r - 1][x - 1] = -2;
					st = "";
				}
				else st += s[j];
			}
			if (!st.empty()) x = stoint(st);
			a[r - 1][x - 1] = -2;
		}

		sol(0, 0);

		cout << sm << endl;
		sm = 0;
	}
}
