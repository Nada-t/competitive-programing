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
	int n, l = 0, r = 0, len = 1e9;
	string s;
	set<char> st1, st2;
	map<char, int>mp;

	cin >> n >> s;
	for (int i = 0;i < s.size();i++)
	{
		st1.insert(s[i]);
	}

	while (l < n)
	{
		//cout << s[l] << "  " << s[r] << "  " << st2.size() <<" "<< len << endl;
		while (r < n && st2.size() < st1.size())
		{
			st2.insert(s[r]);
			mp[s[r]]++;
			r++;
		}
		if (st2.size() == st1.size()) len = min(len, abs(l - r));
		if (mp[s[l]] < 2) st2.erase(s[l]);
	    mp[s[l]]--;
		l++;
	}
	if (len != 1e9) cout << len << endl;
	else cout << 0 << endl;
}