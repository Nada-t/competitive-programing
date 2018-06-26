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
	int n, m;

	while (cin >> n >> m)
	{
		int a[100002];
		map<int, int> mp;
		map<pair<int, int>, int> p;

		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			mp[a[i]]++;
			p[{mp[a[i]], a[i]}] = i + 1;
		}
		while (m--)
		{
			int x, y;

			cin >> x >> y;
			if (p[{x, y}] != 0)
			{
				cout << p[{x, y}] << endl;
			}
			else cout << 0 << endl;
		}
	}

}