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
	int n, m, a[100004], b[100004], sm = 0;
	map <int, int> mp;

	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1;i >= 0;i--)
	{
		if (mp[a[i]] == 0)
		{
			sm++;
		}
		b[i] = sm;
		mp[a[i]]++;
	}
	while (m--)
	{
		int l;
		cin >> l;
		
		cout << b[l - 1] << endl;
	}
}

