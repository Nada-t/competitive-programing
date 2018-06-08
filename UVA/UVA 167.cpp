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

int  sm = 0, t, res = 0;
int dpd2[100] = { 0 }, dpd1[100] = { 0 }, dp[100] = { 0 }, a[100][100];

void sol(int x)
{
	if (x == 8)
	{
		res = max(res, sm);
	}
	for (int i = 0;i < 8;i++)
	{
		if (!dp[i] && !dpd1[(x - i) + 7] && !dpd2[x + i])
		{
			dp[i] = dpd1[(x - i) + 7] = dpd2[x + i] = 1;
			sm += a[i][x];
			sol(x + 1);
			sm -= a[i][x];
			dp[i] = dpd1[(x - i) + 7] = dpd2[x + i] = 0;
		}
	}
}

int  main()
{
	fast();
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof dp);
		memset(dpd1, 0, sizeof dpd1);
		memset(dpd2, 0, sizeof dpd2);
		sm = 0, res = 0;
		
		for (int i = 0;i < 8;i++)
		{
			for (int j = 0;j < 8;j++)
			{
				cin >> a[i][j];
			}
		}
		
		sol(0);
		cout << setw(5) << res << endl;
	}
}
