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
bool check(vector<int> v1,vector<int> v2)
{
	for (int i = 0;i < min(v1.size(), v2.size());i++)
	{
		if (v1[i] != v2[i]) return 0;
	}
	return 1;
}
int  main()
{
	fast();
	int n;
	while (cin >> n && n > 0)
	{
		int x, sm = 0, ans = 0, mx = 0;
		map<vector<int>, int> mp;
		vector<int>v;

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < 5;j++)
			{
				cin >> x;
				v.push_back(x);
			}
			sort(v.begin(), v.end());
			mp[v]++;
			mx = max(mx, mp[v]);
			v.clear();
		}
		for (map<vector<int>, int>::iterator it = mp.begin();it != mp.end();it++)
		{
			//cout << it->second << endl;
			if (it->second == mx) ans += mx;
		}
		cout << ans << endl;
	}
	
}