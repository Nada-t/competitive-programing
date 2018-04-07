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
	int n, q, x;
	vector<int> v;

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	cin >> q;
	for (int i = 0;i < q;i++)
	{
		cin >> x;

		int x1 = (lower_bound(v.begin(), v.end(), x) - v.begin());
		int x2 = (upper_bound(v.begin(), v.end(), x) - v.begin());
		
		if (x1 > 0) cout << v[x1 - 1] << " ";
		else cout << "X" << " ";

		if (x2 < n) cout << v[x2] << endl;
		else cout << "X" << endl;
		
	}
}