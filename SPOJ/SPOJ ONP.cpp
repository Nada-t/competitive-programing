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
		stack<int>st, st2;
		string s, ss = "", ans = "";

		cin >> s;
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == '(' || s[i] == ')')
			{
				if (!st.empty() && st.top() == '(' && s[i] == ')')
				{
					st.pop();
					ans += ss;
					ans += st2.top();
					st2.pop();
					ss = "";
				}
				else if (s[i] == '(')
				{
					st.push(s[i]);
				}
				
			}
			if (!isalpha(s[i]) && s[i] != '(' && s[i] != ')') st2.push(s[i]);
			else if (isalpha(s[i])) ss += s[i];
		}
		cout << ans << endl;
	}
	
}