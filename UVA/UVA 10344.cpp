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
bool b = 0;
int n, ln = 0, dp[100][100], a[10];
bool sol(int y, int x, int j, int ln)
{
	if (j != -1) ln++;

	dp[y][j] = 1;
	if (ln == 5)
	{
		if (x == 23)
		{
			b = 1;
			dp[y][j] = -1;
			ln--;
			return 1;
		}
		dp[y][j] = -1;
		ln--;
		return 0;
	}
	
	for (int i = 0;i < 5;i++)
	{
		if (dp[a[i]][i] == -1 && i != j)
		{
			if (j == -1)
			{
				if (sol(a[i], x + a[i], i, ln))
				{
					dp[y][j] = -1;
					ln--;
					return 1;
				}
			}
			else if (sol(a[i], x + a[i], i, ln) || sol(a[i], a[i] * x, i, ln) || sol(a[i], x - a[i], i, ln))
			{
				dp[y][j] = -1;
				ln--;
				return 1;
			}
		}
	}
	dp[y][j] = -1;
	ln--;
	return 0;
}
int  main()
{
	fast();

	while (cin >> a[0] && a[0] != 0)
	{
		memset(dp, -1, sizeof dp);
		ln = 0, b = 0;
		for (int i = 1;i < 5;i++)
			cin >> a[i];

		sol(0, 0, -1, 0);

		if (b) cout << "Possible" << endl;
		else cout << "Impossible" << endl;

	}
}
