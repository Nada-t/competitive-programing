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
	int t, z = 1;
	cin >> t;
	while (t--)
	{
		int n, sm = 0, x = 0;
		string s;
		bool b = 0;

		cin >> n >> s;
		for (int i = 0;i < s.size();i++)
		{
		    if(s[i]=='#' && b==0) continue;
			if (s[i] == '.') b = 1;
			x++;
			if (x == 3 && b) 
			{
				sm++;
				x = 0;
				b = 0;
			}
		}
		if(b) sm++;
		cout << "Case " << z++ << ": " << sm << endl;
	}
}