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

	cin >> n;
	while (n--)
	{
		map<char, int>mp;
		string s;
		int sm = 0;

		cin >> s;
		for (int i = 0;i < s.size();i++)
		{
			mp[s[i]]++;
		}

		while (mp['A'] >= 3 && mp['R'] >= 2 && mp['M'] >= 1 && mp['G'] >= 1 && mp['I'] >= 1 && mp['T'] >= 1)
		{
			sm++;
			mp['A'] -= 3;
			mp['R'] -= 2;
			mp['M'] -= 1;
			mp['G'] -= 1;
			mp['I'] -= 1;
			mp['T'] -= 1;
		}
		cout << sm << endl;
	}
}