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
	int t;
	cin >> t;
	while (t--)
	{
		long long n, h, a[1000001] = { 0 }, x, y, mn = 1e9;
		
		cin >> n >> h;
		for (int i = 1;i <= n;i++)
		{
			cin >> x >> y;
			a[x + 1]++;
			a[y + 2]--;
		}
		for (int i = 1;i <= n;i++)
		{
			a[i] += a[i - 1];
		}
		for (int i = 1;i <= n;i++)
		{
			a[i] += a[i - 1];
		}
		for (int i = h;i <= n;i++)
		{
			mn = min(mn, ((h*n) - (a[i] - a[i - h])));
		}
		cout << mn << endl;
	}
	
}