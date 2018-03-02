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
	int l;


	while (cin >>l && l > 0 )
	{
		string s;
		char ch='.';
		int mn = 1e7, x = 0, idx;

		cin >> s;
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == 'Z')
			{
				x = 1;
				break;
			}
			else
			{
				if (ch == '.')
				{
					ch = s[i];
					idx = i;
					continue;
				}
				if (ch != s[i] && isalpha(s[i]))
				{
					mn = min(mn, abs(i - idx));
					ch = s[i];
					idx = i;
				}
				else if (ch == s[i])
				{
					idx = i;
				}
			}
		}
		if (x) cout << 0 << endl;
		else cout << mn << endl;
	}
	
}