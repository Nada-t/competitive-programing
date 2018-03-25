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
		int n, sm = 0;
		vector<int> v(1001);

		cin >> n;
		for (int i = 0;i < n;i++)
		{
			cin >> v[i];
		}
		for (int i = 1;i < n;i++)
		{
			for (int j = 0;j < i;j++)
			{
				if (v[j] <= v[i]) sm++;
			}
		}
		cout << sm << endl;
	}
}