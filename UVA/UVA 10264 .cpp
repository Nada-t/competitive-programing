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
int  main()
{
	fast();
	int n;
	while (cin >> n)
	{
		int x, ans = 0;
		vector<int> v, vp;
		for (int i = 0;i < (1 << n);i++)
		{
			cin >> x;
			v.push_back(x);
		}

		for (int i = 0;i < (1 << n);i++)
		{
			int pon = 0;
			for (int j = 0;j < (1 << n);j++)
			{
				if (i != j && (((i^j)&((i^j) - 1)) == 0))
				{
					pon += v[j];
				}
			}
			vp.push_back(pon);
		}

		for (int i = 0;i < (1 << n);i++)
		{
			for (int j = 0;j < (1 << n);j++)
			{
				int sum = vp[i];
				if (i != j && (((i^j)&((i^j) - 1)) == 0))
				{
					sum += vp[j];
				}
				ans = max(ans, sum);
			}
		}
		cout << ans << endl;
	}

}
