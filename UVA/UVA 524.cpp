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

int n, dp[100];
vector<vector<int>> vv;
vector<int> v;
bool prime(int x)
{
	for (int i = 2;i*i <= x;i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}

void sol(int x)
{
	dp[x] = 1;
	for (int i = 1;i <= n;i++)
	{
		if (dp[i] == -1 && x != i)
		{
			if (prime(i + x))
			{
				v.push_back(i);
				sol(i);
			}
		}
	}
	if (v.size() < n)
	{
		dp[x] = -1;
		v.pop_back();
		return;
	}
	if (v.size() == n)
	{
		if (prime(1 + x))
		{
			vv.push_back(v);
		}
		dp[x] = -1;
		v.pop_back();
		return;

	}
}
int  main()
{
	fast();

	int z = 1;
	while (cin >> n)
	{
		memset(dp, -1, sizeof dp);
		v.clear();
		vv.clear();

		v.push_back(1);
		dp[1] = 1;
		sol(1);

		if (z > 1) cout << endl;
		cout << "Case " << z++ << ":" << endl;
		for (int i = 0;i < vv.size();i++)
		{
			for (int j = 0;j < n;j++)
			{
				cout << vv[i][j] ;
				if (j < n - 1) cout << " ";
			}

			cout << endl;
		}
	}


}
