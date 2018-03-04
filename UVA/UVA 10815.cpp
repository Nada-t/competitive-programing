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
	vector <string> v;
	map<string, int> mp;

	while (getline(cin, s))
	{
		string ss = "";
	
		for (int i = 0;i < s.size();i++)
		{
			if (isalpha(s[i]))
			{
				ss +=tolower(s[i]);
			}
			else if (ss != "")
			{
				if (mp[ss] == 0)
				{
					mp[ss]++;
					v.push_back(ss);
				}
				ss = "";
			}
		}
		if (mp[ss] == 0 && ss != "")
		{
			mp[ss]++;
			v.push_back(ss);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++)
	{
		cout << v[i] << endl;
	}
}