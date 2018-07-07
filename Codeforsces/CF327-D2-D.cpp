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
int n, m, x = 0;
char a[505][505];
int vis[505][505] = { 0 };
vector<pair<char, pair<int, int>>> v;

bool val(int i, int j)
{
	return (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && a[i][j] == '.');
}

void dfs(int i,int j)
{
	x++;
	vis[i][j] = 1;
	v.push_back({ 'B',{i + 1,j + 1} });
	
	if (val(i + 1, j)) dfs(i + 1, j);
	if (val(i - 1, j)) dfs(i - 1, j);
	if (val(i, j + 1)) dfs(i, j + 1);
	if (val(i, j - 1)) dfs(i, j - 1);

	x--;
	if (x != 0)
	{
		v.push_back({ 'D',{ i + 1,j + 1 } });
		v.push_back({ 'R',{ i + 1,j + 1 } });
	}
}
int  main()
{
	//fast();
	scanf("%d%d", &n, &m);

	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> a[i][j];

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (a[i][j] == '.' && vis[i][j] == 0)
			{
				x = 0;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", v.size());
	for (int i = 0;i < v.size();i++)
	{
		printf("%c %d %d\n", v[i].first, v[i].second.first, v[i].second.second);
	}
}

