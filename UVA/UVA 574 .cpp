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
	int t, n;
	while (cin >> t >> n && t && n)
	{
		long long sm = 0, a[100001];
		vector<long long> v;
		vector<vector<long long>> vv;
		map<vector<long long>, int> mp;

		for (int i = 0;i < n;i++)
			cin >> a[i];

		for (int i = 0;i < (1 << n);i++)
		{
			v.clear();
			sm = 0;
			for (int j = 0;j < n;j++)
			{
				if (i& (1 << j))
				{
					sm += a[j];
					v.push_back(a[j]);
					//cout << a[j] << "   " << sm << endl;
				}
			}
			if (sm == t)
			{
				sort(v.begin(), v.end());
				reverse(v.begin(), v.end());
				if (mp[v] == 0)
				{
					mp[v]++;
					vv.push_back(v);
				}
			}
		}
		sort(vv.begin(), vv.end());
		cout << "Sums of " << t << ":" << endl;
		if (vv.size() == 0)
		{
			cout << "NONE" << endl;
			continue;
		}
		for (int i = vv.size() - 1; i >= 0;i--)
		{
			for (int j = 0;j < vv[i].size();j++)
			{
				cout << vv[i][j];
				if (j < vv[i].size() - 1) cout << "+";
			}
			cout << endl;
		}
	}
}
