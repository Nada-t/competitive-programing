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
	int n, m;

	while (cin >> n >> m)
	{
		if (!n && !m) break;

		map<int, int> mp;
		int x, sm = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> x;
			mp[x]++;
		}
		for (int i = 0;i < m;i++)
		{
			cin >> x;
			if (mp[x] != 0) sm++;
		}

		cout << sm << "\n";
	}
}