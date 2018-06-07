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
bool b = 0;
pair<int, int> p1, p2;
int n, m, len = 0, a1, a2;
vector<pair<int ,int>> v;
map<pair<pair<int, int>, int>,int> mpp;
void sol(pair<int, int> p, int j, int x)
{
	mpp[{p, j}]++;
	if (len > n)
	{
		len--;
		mpp[{p, j}] = 0;
		return;
	}
	if (len == n && (x == p2.first))
	{
		b = 1;
		len--;
		mpp[{p, j}] = 0;
		return;
	}
	for (int i = 0;i < m;i++)
	{
		if (mpp[{v[i], i}] == 0 && i != j)
		{
			if (v[i].first == x)
			{
				len++;
				sol(v[i], i, v[i].second);
			}
			else if (v[i].second == x)
			{
				len++;
				sol(v[i], i, v[i].first);
			}
		}
	}
	len--;
	mpp[{p, j}] = 0;
	return;
}
int  main()
{
	fast();

	while (cin >> n && n != 0)
	{
		b = 0;
		len = 0;
		v.clear();
		mpp.clear();
		cin >> m >> p1.first >> p1.second >> p2.first >> p2.second;
		for (int i = 0;i < m;i++)
		{
			cin >> a1 >> a2;
			v.push_back({ a1,a2 });
		}
		sol(p1,-1,p1.second);

		if (b) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}
