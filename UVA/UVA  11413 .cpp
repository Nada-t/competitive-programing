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
int n, m, a[1002];
bool check(int x)
{
	int sm = 0, cnt = 1;
	for (int i = 0;i < n;i++)
	{
		if (a[i] + sm <= x) sm += a[i];
		else if (a[i] + sm > x)
		{
			cnt++;
			if (cnt > m) return 0;
			if (a[i] > x) return 0;
			else sm = a[i];
		}
	}
	return 1;
}
int  main()
{
	fast();
	while (cin >> n >> m)
	{
		for (int i = 0;i < n;i++)
			cin >> a[i];
		
		int l = 1, r = 1e9, md, ans;
		while (l <= r)
		{
			md = (l + r) / 2;
			if (check(md))
			{
				ans = md;
				r = md - 1;
			}
			else l = md + 1;
		}
		cout << ans << endl;
	}
}