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
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (((p1.first == p2.first) && (p1.second > p2.second)) || (p1.first < p2.first)) return 1;
	return 0;
}
int  main()
{
	fast();
	int x, y, s, n, sm = 0;
	vector<pair<int, int>> v;

	cin >> s >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0;i < n;i++)
	{
		if (v[i].first < s) s += v[i].second;
		else { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
}