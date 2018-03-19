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
	int n, a;
	vector<int> v, v1;

	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int x = n, i = 0;
	while (x)
	{
		//cout << v[i] << " " << v[x - 1] << endl;
		v1.push_back(v[i]);
		v1.push_back(v[x - 1]);
		i++;
		x--;
	}
	for (int i = 0;i < n;i++)
		cout << v1[i] << " ";
	cout << endl;
}