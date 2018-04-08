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
	int t, z = 1;
	cin >> t;
	while (t--)
	{
		int n, p, q, a[33], sm = 0, y = 0;
		bool b = 0;

		cin >> n >> p >> q;
		for (int i = 0;i < n;i++)
			cin >> a[i];

		for (int i = 0;i < min(n,p);i++)
		{
			if (q >= y + a[i])
			{
				y += a[i];
				sm++;
			}
		}
		cout << "Case " << z++ << ": " << sm << endl;
	}
}