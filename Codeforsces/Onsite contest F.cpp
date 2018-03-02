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
bool chek(string s)
{
	for(int i=0;i<s.size();i++)
		if (s[i] != '?')
		{
			return 0;
		}
	return 1;
}
int  main()
{
	fast();
	string s;
	int a[27],mn=INT_MAX;
	long long sm = 0;
	char c;

	cin >> s;
	for (int i = 0;i < 26;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i < s.size();i++)
	{
		if (s[i] != '?'&& s[i - 1] != '?')
			sm += abs(a[s[i] - 'a'] - a[s[i - 1] - 'a']);
		//cout << a[s[i] - 'a'] << "$$" << endl;
	}
	if (chek(s))
	{
		if (s.size() > 1)
		{
			s.assign(s.size(), 'a');
			cout << 0 << endl;
			cout << s << endl;
		}
		else
		{
			int m = INT_MAX;
			char h;
			for (int i = 0;i < 26;i++)
			{
				if (a[i] < m)
				{
					m = a[i];
					h = i + 'a';
				}
			}
			cout << m << endl;
			cout << h << endl;
		}
		
		return 0;
	}
	if (s[0] == '?')
	{
		int i = 0;
		char ch;
		while (1)
		{
			if (s[i] != '?')
			{
				ch = s[i];
				break;
			}
			i++;
		}
		string sx = "";
		sx.assign(i, ch);
		s.replace(0,i, sx);
	}

	for (int i = 1;i < s.size();i++)
	{
		int ss = INT_MAX, len = 0, idx, ii = -1;
		string s1="";
		char cc = s[i - 1];

		if (s[i] == '?')
		{
			idx = i;
			ii = i;
			while (1 && ii<s.size())
			{
				if (s[ii] != '?')
				{
					break;
				}
				len++;
				ii++;
			}
			for (int j = 0;j < 26;j++)
			{
				if (ii >= s.size())
				{
					if ((abs(a[cc - 'a'] - a[j])) < ss)
					{
						c = j + 'a';
						ss = abs(a[cc - 'a'] - a[j]);
					}
				}
				else if ((abs(a[cc - 'a'] - a[j]) + abs(a[s[ii] - 'a'] - a[j])) < ss)
				{
					c = j + 'a';
					ss = (abs(a[cc - 'a'] - a[j]) + abs(a[s[ii] - 'a'] - a[j]));
				}
			}
			for (int k = idx;k < ii;k++)
			{
				s[k] = c;
			}
			//cout << ss << endl;
			sm += ss;
		}
		if (ii != -1)i = ii;
	}
	cout << sm << endl;
	cout << s << endl;
}