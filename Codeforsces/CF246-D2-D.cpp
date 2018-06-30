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
int  main()
{
	fast();
	int n, m, cl[100002], mx = -1, ans;
	map<pair<int, int>, int> mp;
	map<int, int> p;

	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> cl[i];
		p[cl[i]] = 0;
	}
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		if (mp[{cl[u], cl[v]}] == 0 && cl[v] != cl[u]) p[cl[u]]++, mp[{cl[u], cl[v]}]++;
		if (mp[{cl[v], cl[u]}] == 0 && cl[v] != cl[u]) p[cl[v]]++, mp[{cl[v], cl[u]}]++;
	}
	for (map<int, int>::iterator it = p.begin();it != p.end();it++)
	{
		if (it->second > mx)
		{
			mx = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
}