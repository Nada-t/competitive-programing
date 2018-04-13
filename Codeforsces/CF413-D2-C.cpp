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
	int n, m, a[101], b;
	long long sm = 0;
	vector<int> v;

	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0;i < m;i++)
	{
		cin >> b;
		v.push_back(a[b - 1]);
		a[b - 1] = 0;
	}
	for (int i = 0;i < n;i++)
	{
		sm += a[i];
	}
	//cout << sm << endl;
	sort(v.begin(),v.end());
	reverse(v.begin(), v.end());

	for (int i = 0;i < m;i++)
	{
		if (v[i] > sm) sm += v[i];
		else sm += sm;
	}
	cout << sm << endl;

}