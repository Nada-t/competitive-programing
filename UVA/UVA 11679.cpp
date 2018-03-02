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
	int n, b;


	while (cin >> b >> n && b > 0 && n > 0)
	{
		long long mr[22], a[22] = { 0 }, aa[22] = { 0 }, z = 0;

		for (int i = 1;i <= b;i++)
		{
			cin >> mr[i];
		}
		for (int i = 0;i < n;i++)
		{
			int d, c, v;
			cin >> d >> c >> v;

			a[c] += v;
			aa[d] += v;
		}

		for (int i = 1;i <= b;i++)
		{
			if (aa[i] > a[i] + mr[i])
			{
				z = 1;
				break;
			}
		}
		if(!z) cout << 'S' << endl;
		else cout<< 'N' << endl;
	}
	
}
