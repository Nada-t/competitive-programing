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

	getline(cin, s);
	for (int i = 0;i < s.size()-1;i++)
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
		if (s[i] == ' ' && (s[i + 1] == ',' || s[i + 1] == '.' || s[i + 1] == '?' || s[i + 1] == '!'))
		{
			s.erase(i, 1);
		}
		if ((s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!') && isalpha(s[i + 1]))
		{
			s.insert(i+1," ");
		}
	}
	cout << s << endl;
}