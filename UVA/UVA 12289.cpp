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
	string s, s1 = "one", s2 = "two", s3 = "three";

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> s;
		if (s.size() == s1.size())
		{
			int x1 = 0, x2 = 0;
			for (int j = 0;j < s1.size();j++)
			{
				if (s[j] == s1[j]) x1++;
				if (s[j] == s2[j]) x2++;
			}
			if (x1 > x2) cout << 1 << endl;
			else cout << 2 << endl;
		}
		else
		{
			cout << 3 << endl;
		}
	}

}