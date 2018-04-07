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
	int n, q, z = 1;

	while (cin >> n >> q)
	{
		if (n == 0 && q == 0) break;

		int x;
		vector<int> v(n);

		for (int i = 0;i < n;i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		cout << "CASE# " << z++ << ":" << endl;
		for (int i = 0;i < q;i++)
		{
			cin >> x;
			int x2 = (lower_bound(v.begin(), v.end(), x ) - v.begin());

			if (v[x2] != x) cout << x << " not found" << endl;
			else cout << x << " found at " << x2 + 1 << endl;

		}
	}
	
}