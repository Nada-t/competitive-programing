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

	string s;
	while (getline(cin,s))
	{
		vector<string > v;
		string ss = "";

		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == ' ')
			{
				v.push_back(ss);
				ss = "";
			}
			else
			{
				ss += s[i];
			}
		}
		v.push_back(ss);

		for (int i = 0;i < v.size();i++)
		{
			reverse(v[i].begin(), v[i].end());
		}
		for (int i = 0;i < v.size();i++)
		{
			cout << v[i];
			if (i < v.size() - 1) cout << " ";
		}
		cout << endl;
	}
}