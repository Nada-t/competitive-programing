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
	int n, l, r, x, a[16], sm = 0, sum = 0, mx = INT_MIN, mn = INT_MAX;
	vector<int> v;

	cin >> n >> l >> r >> x;
	for (int i = 0;i < n;i++)
		cin >> a[i];

	for (int i = 0;i < (1 << n);i++)
	{
		for (int j = 0;j < n;j++)
		{
			
			if (i&(1 << j))
			{
				sm += a[j];
				mx = max(mx, a[j]);
				mn = min(mn, a[j]);
			}
		}
		//cout << sm << endl;
		if (sm >= l && sm <= r && (mx - mn >= x))
		{
			sum++;
		}
		sm = 0;
		mx = INT_MIN;
		mn = INT_MAX;
	}
	cout << sum << endl;
}
