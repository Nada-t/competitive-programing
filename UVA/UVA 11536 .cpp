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
	int t, x = 1;
	cin >> t;
	while (t--)
	{
		map<long long, int>mp;
		set<long long> st;
		vector<long long> v;
		int n, m, k, len = 1e9, l = 0, r = 0;
		cin >> n >> m >> k;

		v.resize(n);
		v[0] = 1, v[1] = 2, v[2] = 3;

		for (int i = 3;i < n;i++)
		{
			v[i] = ((v[i - 1] + v[i - 2] + v[i - 3]) % m) + 1;
		}
		while (l < n)
		{
			while (r < n && mp.size() < k)
			{
				if (v[r] > 0 && v[r] <= k)
				{
					mp[v[r]]++;
				}
				r++;
			}
			if (mp.size() == k) len = min(len, abs(l - r));
			if (mp[v[l]] < 2) mp.erase(v[l]);
			else mp[v[l]]--;
			l++;
		}
		cout << "Case " << x++ << ": ";
		if (len != 1e9) cout << len << endl;
		else cout << "sequence nai" << endl;
	}
}