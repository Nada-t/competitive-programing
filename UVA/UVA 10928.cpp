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
	int t, z = 0;
	cin >> t;
	while (t--)
	{
		int p, mn=10000000;
		vector<int> v;

		cin >> p;
		cin.ignore();
		
		for (int i = 0;i < p;i++)
		{
			string s;
			getline(cin, s);
			int sz = 0;
			for (int j = 0;j < s.size();j++)
			{
				if (s[j] == ' ') sz++;
			}
			mn = min(mn, sz);
			v.push_back(sz);
		}
		int l = 0;
		for (int i = 0;i < v.size();i++)
		{
			if (v[i] == mn)
			{
				if (l) cout << " ";
				cout << i + 1;
				l++;
			}
		}
		cout << endl;
	}
}