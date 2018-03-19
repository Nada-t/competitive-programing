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
	string s, ss = "";
	vector<string> v;
	map < string, int > mp;

	while (getline(cin, s))
	{
		if (ss.empty()) ss += s;
		else if (!ss.empty() && ss[ss.size() - 1] != '-') ss += " ", ss += s;
		else if (!ss.empty() && ss[ss.size() - 1] == '-') ss.erase(ss.size() - 1, 1), ss += s;
	}
	string c = "";
	//cout << ss << endl;
	for (int i = 0;i < ss.size();i++)
	{
		if (!isalpha(ss[i]) && ss[i] != '-' && c != "-" && c != "")
		{
			mp[c]++;
			c = "";
		}
		else if (isalpha(ss[i]) || ss[i] == '-') c += tolower(ss[i]);
	}
	if (c != "") mp[c]++;
	for (map<string, int>::iterator it = mp.begin();it != mp.end();it++)
	{
		cout << it->first << endl;
	}
}