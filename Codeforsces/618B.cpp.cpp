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
	int n, a[55][55], b[55];
	map<int, int> mp;

	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];

	for (int i = 0;i < n;i++)
	{
		int mx = 0;
		for (int j = 0;j < n;j++)
		{
			mx = max(mx, a[j][i]);
		}
		if (mp[mx] == 0)
		{
			b[i] = mx;
			mp[mx]++;
		}
		else
			b[i] = mx + 1;
	}
	for (int i = 0;i < n;i++)
		cout << b[i] << " ";

	cout << endl;
}