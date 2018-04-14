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
	int n, m;
	while (cin >> n >> m)
	{
		int sm = 0, sm1 = 0, a[100001];
		vector<int> v1, v2;
		for (int i = 0;i < m;i++)
			cin >> a[i];
		for (int i = 0;i < (1 << m);i++)
		{
			v1.clear();
			sm = 0;
			for (int j = 0;j < m;j++)
			{
				if (i& (1 << j))
				{
					sm += a[j];
					v1.push_back(a[j]);
					//cout << a[j] << "   " << sm << endl;
				}
			}
			if (sm <= n && sm1 < sm)
			{
				sm1 = sm;
				v2.clear();
				v2 = v1;
			}
			else if (sm <= n && sm1 == sm)
			{
				if (v1.size() > v2.size())
				{
					v2.clear();
					v2 = v1;
				}
			}
		}
		for (int i = 0;i < v2.size();i++)
			cout << v2[i] << " ";
		cout << "sum:" << sm1 << endl;
	}
}