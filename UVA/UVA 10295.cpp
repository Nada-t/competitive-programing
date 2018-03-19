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
	int m, n;
	map<string, int> mp;

	cin >> m >> n;
	while (m--)
	{
		string s;
		int x;

		cin >> s >> x;
		mp[s] = x;
	}
	while (n--)
	{
		long long sm = 0;
		string s, c = "";

		getline(cin, s, '.');
		for (int i = 0;i < s.size();i++)
		{
			if (!isalpha(s[i]))
			{
				if (mp[c] != 0) sm += mp[c];
				c = "";
			}
			else
			{
				if (isalpha(s[i])) c += s[i];
			}
		}
		cout << sm << endl;
	}
}