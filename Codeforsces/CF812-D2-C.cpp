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
long long n, s, a[100002], sm;
bool check(long long x)
{
	sm = 0;
	long long z;
	vector<long long> v;
	for (int i = 0;i < n;i++)
	{
		z = (a[i] + ((i + 1)*x));
		v.push_back(z);
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < x;i++)
	{
		sm += v[i];
	}
	if (sm <= s) return 1;
	else  return 0;
}
int  main()
{
	fast();
	
	cin >> n >> s;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	//sort(a, a + n);
	long long l = 1, r = n, md, ans = 0, cnt = 0;
	while (l <= r)
	{
		md = (l + r) / 2;
		if (check(md))
		{
			ans = md;
			cnt = sm;
			l = md + 1;
		}
		else r = md - 1;
	}
	
	cout << ans << " " << cnt << endl;
	
}