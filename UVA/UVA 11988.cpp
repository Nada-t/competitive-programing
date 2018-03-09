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

	while (cin >> s)
	{
		string c = "", cc = "";
		vector<string> v;
		stack<char> st;
		int idx = 0;
		bool b1 = 0, b2 = 0;

		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == '[' || s[i] == ']')
			{
				/*if (!st.empty() && (st.top() == '['&& s[i] == ']'))
				{
					st.pop();
					v.push_back(c);
					c = "";
				}
				else
					st.push(s[i]);*/
				st.push(s[i]);
				v.push_back(c);
				c = "";
			}
			else
			{
				if (!st.empty() && st.top() == '[')
					c += s[i];
				else
					cc += s[i];
			}
			
		}
		if (c != "") v.push_back(c);
		for (int i = v.size()-1;i >=0;i--)
			cout << v[i];
		cout << cc << "\n";

	}
}