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
	long long n, x, sod = 0, sov = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> x;
		if (x % 2 == 0)
			sov += x;
		else
		{
			sod += x;
			v.push_back(x);
		}
	}
	if (v.size() % 2 == 0)
	{
		cout << sov + sod << endl;
	}
	else
	{
		sort(v.begin(), v.end());
		sod -= v[0];
		cout<< sov + sod << endl;
	}
}