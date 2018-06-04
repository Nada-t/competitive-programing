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
	int l, n;
	while (cin >> l >> n && l > 0 && n > 0)
	{
		vector<pair<int, int>> v;
		int x, y, st = 0, ed = 0, j = 0, sm = 0;

		for (int i = 0;i < n;i++)
		{
			cin >> x >> y;
			v.push_back({ x - y,x + y });
		}

		sort(v.begin(), v.end());

		while (st < l && j < n)
		{
			int s = -1;
			while (j<n && v[j].first <= st )
			{
				ed = max(ed, v[j].second);
				j++;
				s++;
			}
			sm += s;
			if (st == ed) break;
			st = ed;
		}
		
		if (st < l)
		{
			cout << -1 << endl;
			continue;
		}
		sm += (n - j);
		cout << sm << endl;
	}
}
