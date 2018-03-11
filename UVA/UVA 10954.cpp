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
	int n;

	while (cin >> n && n != 0)
	{
		int a[5002];
		long long sm = 0;

		for (int i = 0;i < n;i++)
			cin >> a[i];

		sort(a, a + n);
		for (int i = 1;i < n;i++)
		{
			a[i] += a[i - 1];
			sm += a[i];
			sort(a, a + n);
		}
		cout << sm << endl;
	}
}