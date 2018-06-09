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

const double eps = 1e-7;
double n, k, a[10002];
double st = 0, ed = 10002, sum = 0;

bool sol(double x)
{
	double sm = 0;
	for (int i = 0;i < n;i++)
	{
		if (a[i] > x) sm += ((a[i] - x)*k) / 100;
	}
	return sm + (n*x) < sum;
}
int  main()
{
	fast();

	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	while ((ed - st) > eps)
	{
		double md = (st + ed) / 2;
		if (sol(md)) st = md;
		else ed = md;
	}
	cout << fixed << setprecision(9) << st << endl;
}
