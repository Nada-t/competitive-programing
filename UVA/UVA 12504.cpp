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
	int t;
	cin >> t;
	while (t--)
	{
		map < string, string > mp;
		vector < string > v1, v2, v3,vv;
		string s1, s2, ss1 = "", ss2 = "";

		cin >> s1 >> s2;
		for (int i = 0;i < s1.size();i++)
		{
			if (isalpha(s1[i]))
			{
				ss1 += s1[i];
			}
			if (isdigit(s1[i]))
			{
				ss2 += s1[i];
			}
			if (s1[i] == ',' || s1[i] == '}')
			{
				mp[ss1] = ss2;
				ss1 = "";
				ss2 = "";
			}
		}
		ss1 = "", ss2 = "";
		for (int i = 0;i < s2.size();i++)
		{
			if (isalpha(s2[i]))
			{
				ss1 += s2[i];
			}
			if (isdigit(s2[i]))
			{
				ss2 += s2[i];
			}
			if (s2[i] == ',' || s2[i] == '}')
			{
				if (ss1 != "" && mp[ss1] == "") v1.push_back(ss1);
				if (ss1 != "" && mp[ss1] != "" && mp[ss1] != ss2) v3.push_back(ss1), mp.erase(ss1);
				if (mp[ss1] == ss2) mp.erase(ss1);
				ss1 = "";
				ss2 = "";
			}
		}
		for (map<string, string>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second != "")
				v2.push_back(it->first);
		}
		if (!v1.empty())
		{
			sort(v1.begin(), v1.end());
			cout <<"+";
			for (int i = 0;i < v1.size();i++)
			{
				cout << v1[i];
				if (i < v1.size() - 1) cout << ',';
			}
			cout << endl;
		}
		if (!v2.empty())
		{
			sort(v2.begin(), v2.end());
			cout << "-";
			for (int i = 0;i < v2.size();i++)
			{
				cout << v2[i];
				if (i < v2.size() - 1) cout << ',';
			}
			cout << endl;
		}
		if (!v3.empty())
		{
			sort(v3.begin(), v3.end());
			cout << "*";
			for (int i = 0;i < v3.size();i++)
			{
				cout << v3[i];
				if (i < v3.size() - 1) cout << ',';
			}
			cout << endl;
		}
		if (v1.empty() && v2.empty() && v3.empty())
		{
			cout << "No changes" << endl;
		}
		cout << endl;
	}
	
}