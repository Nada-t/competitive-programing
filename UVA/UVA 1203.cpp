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
	map<pair<int, int>, int> mp;
	int q, pr;

	while (cin >> s && s != "#")
	{
		cin >> q >> pr;
		mp[{pr, q}] = pr;
	}
	int k;
	cin >> k;
	while (k--)
	{
		map < pair<int, int>, int > ::iterator it = mp.begin();
	
		cout<< it->first.second << endl;
		//it->second += it->first.second;
		int z = it->second + it->first.first;
		mp.insert({ {z, it->first.second } ,it->second });
		mp.erase(it);
	}
}