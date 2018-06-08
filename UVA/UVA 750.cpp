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

int r, c, sm = 0, t;
int dpd2[100] = { 0 }, dpd1[100] = { 0 }, dp[100] = { 0 };
vector<int> v(10);


void sol(int x)
{
	if (x == 8)
	{
		sm++;
		if (sm < 10) cout << " ";
		cout << sm << "      ";
		for (int i = 0;i < 8;i++)
		{
			if (i) cout << " ";
			cout << v[i] + 1;
		}
	    cout << endl;
	}

	if (x == c - 1) sol(x + 1);
	else
	{
		for (int i = 0;i < 8;i++)
		{
			if (!dp[i] && !dpd1[(x - i) + 7] && !dpd2[x + i])
			{
				dp[i] = dpd1[(x - i) + 7] = dpd2[x + i] = 1;
				v[x] = i;
				sol(x + 1);
				dp[i] = dpd1[(x - i) + 7] = dpd2[x + i] = 0;
			}
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
		sm = 0;
		cin >> r >> c;

		v[c - 1] = r - 1;
		dp[r - 1] = 1;
		dpd1[((c - 1) - (r - 1)) + 7] = 1;
		dpd2[(r - 1) + (c - 1)] = 1;

		

		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		
		sol(0);
		if (t > 0) cout << endl;
	}
}
