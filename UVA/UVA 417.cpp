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
string a[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
vector<string> v;
map <string, int> mp, m;
void sub()
{
	for (int i = 0;i < 26;i++)
	{
		v.push_back(a[i]);
		mp[a[i]] = v.size();
	}
	for (int i = 0;i < 26;i++)
	{
		for (int j = i + 1;j < 26;j++)
		{
			string s = a[i] + a[j];
			v.push_back(s);
			mp[s] = v.size();
		}
	}
	for (int i = 0;i < 26;i++)
	{
		for (int j = i + 1;j < 26;j++)
		{
			for (int k = j + 1;k < 26;k++)
			{
				string s = a[i] + a[j] + a[k];
				v.push_back(s);
				mp[s] = v.size();
			}
		}
	}
	for (int i = 0;i < 26;i++)
	{
		for (int j = i + 1;j < 26;j++)
		{
			for (int k = j + 1;k < 26;k++)
			{
				for (int l = k + 1;l < 26;l++)
				{
					string s = a[i] + a[j] + a[k] + a[l];
					v.push_back(s);
					mp[s] = v.size();
				}
			}
		}
	}
	for (int i = 0;i < 26;i++)
	{
		for (int j = i + 1;j < 26;j++)
		{
			for (int k = j + 1;k < 26;k++)
			{
				for (int l = k + 1;l < 26;l++)
				{
					for (int r = l + 1;r < 26;r++)
					{
						string s = a[i] + a[j] + a[k] + a[l] + a[r];
						v.push_back(s);
						mp[s] = v.size();
					}
				}
			}
		}
	}
}
int  main()
{
	fast();
	sub();

	string s;
	while (cin >> s)
	{
		if (mp[s] == 0) cout << 0 << endl;
		else cout << mp[s] << endl;
	}
}