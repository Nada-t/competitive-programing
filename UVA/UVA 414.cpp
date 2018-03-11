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
		cin.ignore();
		string a[14];
		int sm = 0;
		vector<int> v;

		for (int i = 0;i < n;i++)
			getline(cin, a[i]);

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < a[i].size();j++)
			{
				if (a[i][j] != 'X') sm++;
			}
			v.push_back(sm);
			sm = 0;
		}
		sort(v.begin(), v.end());
		for (int i = 1;i < v.size();i++)
		{
			sm += v[i] - v[0];
		}
		cout << sm << endl;
	}
}
