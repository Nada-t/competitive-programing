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
	int n, s;
	while (cin >> n >> s)
	{
		int a[100002], l = 0, r = 0, len = 1e9, sm = 0;
		for (int i = 0;i < n;i++)
			cin >> a[i];

		while (l < n)
		{
			//cout << a[l] << " " << a[r] <<"  "<<sm<< endl;
			while (r < n && sm < s)
			{
				sm += a[r];
				r++;
			}
			if (sm >= s) len = min(len, abs(l - r));
			sm -= a[l];
			l++;
		}
		if (len != 1e9) cout << len << endl;
		else cout << 0 << endl;
	}
}