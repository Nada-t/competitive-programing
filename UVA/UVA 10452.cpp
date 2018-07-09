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
int n, m, sj = 0, si = 0;
char a[10][10];
vector<string> vans;
int vis[10][10] = { 0 };
bool val(char c, int i, int j)
{
	if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j])
	{
		if (c == '@') return (a[i][j] == 'I');
		if (c == 'I') return (a[i][j] == 'E');
		if (c == 'E') return (a[i][j] == 'H');
		if (c == 'H') return (a[i][j] == 'O');
		if (c == 'O') return (a[i][j] == 'V');
		if (c == 'V') return (a[i][j] == 'A');
		if (c == 'A') return (a[i][j] == '#');
		return 0;
	}
	return 0;
}
void sol(int i, int j, vector<string> &vv)
{
	if (a[i][j] == '#' && vv.size() == 7)
	{
		vans = vv;
		return;
	}
	vis[i][j] = 1;
	//cout << a[i][j] << "$$$";
	if (val(a[i][j], i - 1, j))
	{
		vv.push_back("forth");
		sol(i - 1, j, vv);
		vv.pop_back();
	}
	if (val(a[i][j], i, j + 1))
	{
		vv.push_back("right");
		sol(i, j + 1, vv);
		vv.pop_back();
	}
	if (val(a[i][j], i, j - 1))
	{
		vv.push_back("left");
		sol(i, j - 1, vv);
		vv.pop_back();
	}
	vis[i][j] = 0;
}
int  main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		vans.clear();
		memset(vis, 0, sizeof(vis));
		memset(a, '.', sizeof(a));

		cin >> n >> m;
		vector<string> v;
		for (int i = 0;i < n;i++)
			for (int j = 0;j < m;j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@') sj = j, si = i;
			}
		sol(si, sj, v);
		cout << vans[0];
		for (int i = 1;i < vans.size();i++)
			cout << " " << vans[i];
		cout << endl;
	}
}

