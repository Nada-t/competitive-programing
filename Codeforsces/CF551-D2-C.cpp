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
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
long long n, m, a[100002], sop = 0, step;
bool sol(long long x)
{
	long long t = x;
	step = n;
	long long sp1 = sop, an[100002];

	for (int i = 0;i < n;i++)
	{
		an[i] = a[i];
	}

	for (int i = 0;i < m;i++)
	{
		t = x;
		if (an[step - 1] == 0)
		{
			while (an[step - 1] == 0 && step > 0)
			{
				step--;
			}
		}
		if (step == 0) break;
		t -= step;
		while (t >= an[step - 1] &&  step > 0 )
		{
			t-= an[step - 1];
			sp1-= an[step - 1];
			an[step - 1] = 0;
			step--;
		}
		if (t < an[step - 1])
		{
			an[step - 1] -= t;
			sp1 -= t;
		}
	}
	return sp1 <= 0;
}

int  main()
{
	fast();
	
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		sop += a[i];
	}

	long long st = 1, ed = 1e15, ans = 1e15;

	while (st <= ed)
	{
		long long md = (st + ed) / 2;
		if (sol(md))
		{
			ans = min(ans, md);
			ed = md - 1;
		}
		else st = md + 1;
	}
	
	cout << ans << endl;
}
