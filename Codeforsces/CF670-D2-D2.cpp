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
long long n, s, a[100002], b[100002], sm, k;
bool check(long long x)
{
	int z = k;
	for (int i = 0;i < n;i++)
	{
		if (a[i] * x > b[i])
		{
			if (((a[i] * x) - b[i]) > z) return 0;
			z -= ((a[i] * x) - b[i]);
			if (z < 0) return 0;
		}
	}
	return z >= 0;
}
int  main()
{
	fast();

	cin >> n >> k;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	for (int i = 0;i < n;i++)
		cin >> b[i];

	long long l = 1, r = 2e9, md, ans = 0;

	while (l <= r)
	{
		md = (l + r) / 2;
		if (check(md))
		{
			ans = md;
			l = md + 1;
		}
		else r = md - 1;
	}

	cout << ans << endl;
}