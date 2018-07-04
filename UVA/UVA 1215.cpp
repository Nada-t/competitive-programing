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
	int t;
	cin >> t;
	while (t--)
	{
		long long n, a[10005], b[10005] = { 0 };
		long long sm = 0;
		string s;

		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> a[i];
		
		cin >> s;
		for (int i = 0;i < n;i++)
		{
			string s1 = "", s2 = "";
			set<char> st1, st2, st;

			for (int j = 0;j < s.size();j++)
			{
				if (b[j] == 1)
				{
					if (j > a[i])
					{
			    		break;
					}
					s1 = "";
					st1.clear();
					s1 += s[j];
					st1.insert(s[j]);
				}
				else
				{
					if (!s1.empty() && j >= a[i])
					{
						s2 += s[j];
						st2.insert(s[j]);
					}
					else
					{
						s1 += s[j];
						st1.insert(s[j]);
					}
				}
			}
			for (int l = 0;l < s1.size();l++) st.insert(s1[l]);
			for (int l = 0;l < s2.size();l++) st.insert(s2[l]);
			b[a[i]] = 1;

			long long x1 = st1.size();
			long long x2 = st2.size();
			long long x = st.size();
			sm += (x - ((x1 + x2) - x));
		}
		cout << sm << endl;
	}
}