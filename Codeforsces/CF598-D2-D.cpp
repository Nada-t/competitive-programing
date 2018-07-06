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
int n, m, q, x, y, ans = 0, cnt = 0;
char a[1002][1002];
int vis[1002][1002] = { 0 };
map <pair<int, int>, int> mp1;
map<int, int> p;

bool val(int i, int j)
{
	return (i >= 0 && i < n &&j >= 0 && j < m && a[i][j] == '*');
}
bool valid(int i, int j)
{
	return (i >= 0 && i < n &&j >= 0 && j < m && a[i][j] == '.' && vis[i][j] == 0);
}
void sol(int i, int j)
{
	if (vis[i][j] == 1) return;
	vis[i][j] = 1;

	int sm = 0;
	if (val(i + 1, j)) sm++;
	if (val(i - 1, j)) sm++;
	if (val(i, j + 1)) sm++;
	if (val(i, j - 1)) sm++;

	ans += sm;
	mp1[{i + 1, j + 1}] = cnt;

	if (valid(i + 1, j))  sol(i + 1, j); 
	if (valid(i - 1, j))  sol(i - 1, j); 
	if (valid(i, j + 1))  sol(i, j + 1); 
	if (valid(i, j - 1))  sol(i, j - 1);
}
int  main()
{
	fast();

	cin >> n >> m >> q;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> a[i][j];

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (valid(i, j))
			{
				ans = 0;
				cnt++;
				sol(i, j);
				p[cnt] = ans;
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		int f = mp1[{x, y}];
		cout << p[f] << endl;
	}
}